#include "max30102.h"

uint8_t activeLeds = 1;
uint8_t numBitsADC = 18;
uint32_t ledIRBuff[32] =
		{
				0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0};
uint32_t ledRedBuff[32] =
		{
				0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0};


char registerWrite(char addr, char byte)
{
	i2c2_start();
	if (i2c2_send_byte(ADDR_DEVICE << 1))
		return 1;
	if (i2c2_send_byte(addr))
		return 1;
	if (i2c2_send_byte(byte))
		return 1;
	i2c2_stop();
	return 0;
}
char registerRead(char addr)
{
	i2c2_start();
	if (i2c2_send_byte(ADDR_DEVICE << 1))
		return 0xff;
	if (i2c2_send_byte(addr))
		return 0xff;
	i2c2_start();
	if (i2c2_send_byte((ADDR_DEVICE << 1) | 1))
		return 0xff;
	uint8_t rs = i2c2_recv_byte();
	i2c2_stop();
	return rs;
}
char registerBitWrite(char addr, char mask, char bit)
{
	//read current byte of register
	char byteCurr = registerRead(addr);
	//set bit to 0 and keep other bit
	byteCurr &= mask;
	//enable bit and write to register
	byteCurr |= bit;
	return registerWrite(addr, byteCurr);
}

void max30102WakeUp(void){
	registerBitWrite(
		ADDR_SHDN,
		SHDN_MASK,
		SHDN_WAKE_UP
	);
	//registerWrite(0x09, 0x03);
}

void max30102ShutDown(void){
	registerBitWrite(
		ADDR_SHDN,
		SHDN_MASK,
		SHDN_WAKE_UP
	);
}

void softReset()
{
	registerBitWrite(
			ADDR_MODE_CONFIG,
			MODE_CONFIG_RESET_MASK,
			MODE_CONFIG_RESET_EN);
	// Timeout after 100ms
	uint8_t cnt = 0;
	delay_us(100);
	while (cnt++ < 100)
	{
		uint8_t response = registerRead(ADDR_MODE_CONFIG);
		if ((response & MODE_CONFIG_RESET_EN) == 0)
			break;			 //We're done!
		delay_us(100); //Let's not over burden the I2C bus
	}
}
uint8_t max30102Setup(void)
{
	/**
	*@todo: basic config
	*byte powerLevel = 0x1F, 
	*byte sampleAverage = 4, 
	*byte ledMode = 3, i
	*nt sampleRate = 100, 
	*int pulseWidth = 411, 
	*int adcRange = 4096
	* - reset config
	*/
	softReset();
	const uint8_t numOfRegs = 10;
	uint8_t configDataArr[numOfRegs] =
			{
					0x50, //fifo config
					0x83, //mode config
					0x27, //spo2 config
					0,		//reserved
					0x1f, //led1 pa red
					0x1f, //led2 pa ir
					0,		//reserved
					0,		//reserved
					0,		//reserved
					0x21, //multi led mode
			};
	//i2c transaction
	activeLeds = configDataArr[1] == 2 ? 1 : 2;
	i2c2_start();
	if (i2c2_send_byte(ADDR_DEVICE << 1))
		return 1;
	if (i2c2_send_byte(ADDR_FIFO_CONFIG))
		return 2;
	uint8_t i;
	for (i = 0; i < numOfRegs; i++)
		if (i2c2_send_byte(configDataArr[i]))
			return (i + 3);
	i2c2_stop();
	registerBitWrite(0x02, 0x7f, 0x80);
	return 0;
}
uint8_t sampleAvailable()
{
	int8_t pReadPos = registerRead(ADDR_FIFO_RD_PTR);
	int8_t pWritePos = registerRead(ADDR_FIFO_WR_PTR);
	int8_t rs = pWritePos - pReadPos;
	return (rs < 0) ? (rs + 32) : rs;
}
uint8_t getReadPtr()
{
	return registerRead(ADDR_FIFO_RD_PTR);
}
uint8_t getWritePtr()
{
	return registerRead(ADDR_FIFO_WR_PTR);
}
uint32_t combine_sample(uint8_t *arr)
{
	uint32_t rs = 0;
	memcpy(&rs, arr, 3);
	rs >>= (18 - numBitsADC);
	return rs;
}
uint8_t readAllSampleAvailable()
{
	int8_t sampleNums = sampleAvailable();
	uint8_t byteNums = sampleNums * activeLeds * 3;
	//open connection
	i2c2_start();
	if (i2c2_send_byte(ADDR_DEVICE << 1))
		return 0;
	if (i2c2_send_byte(ADDR_FIFO_DATA))
		return 0;
	i2c2_start();
	if (i2c2_send_byte((ADDR_DEVICE << 1) | 1))
		return 0;
	uint8_t j = 0;
	while (byteNums > 0)
	{
		uint8_t i;
		uint8_t sampleRedArr[3];
		uint8_t sampleIRArr[3];
		//read 3 bytes of red
		for (i = 0; i < 3; i++)
			sampleRedArr[2 - i] = i2c2_recv_byte();
		ledRedBuff[j++] = combine_sample(sampleRedArr);
		//read 3 bytes of IR
		if (activeLeds > 1)
		{
			for (i = 0; i < 3; i++)
				sampleIRArr[2 - i] = i2c2_recv_byte();
			ledIRBuff[j - 1] = combine_sample(sampleIRArr);
		}
		//update byteNums
		byteNums -= 3 * activeLeds;
	}
	i2c2_stop();
	registerRead(0x00);
	return sampleNums;
}
uint32_t getRed(uint8_t index)
{
	return ledRedBuff[index];
}
uint32_t getIR(uint8_t index)
{
	return ledIRBuff[index];
}


