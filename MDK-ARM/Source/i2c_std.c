#include "i2c_std.h"

i2c_port i2cPort1={
	I2C1_SCL_GPIO,
	I2C1_SDA_GPIO,
	I2C1_SCL_GPIO_CLK,
	I2C1_SDA_GPIO_CLK,
	I2C1_SCL_Pin,
	I2C1_SDA_Pin
};

i2c_port i2cPort2={
	I2C2_SCL_GPIO,
	I2C2_SDA_GPIO,
	I2C2_SCL_GPIO_CLK,
	I2C2_SDA_GPIO_CLK,
	I2C2_SCL_Pin,
	I2C2_SDA_Pin
};


void set_scl(i2c_port port, u8 val);
void set_sda(i2c_port port, u8 val);
u8 get_sda(i2c_port port);

void i2c_init(i2c_port port);
void i2c_start(i2c_port port);
void i2c_stop(i2c_port port);
char i2c_isReady(i2c_port port, char deviceAddr);
char i2c_send_byte(i2c_port port, char byte);
char i2c_recv_byte(i2c_port port);
void i2c_send_ack(i2c_port port, char ack);
char i2c_recv_ack(i2c_port port);
void sda_input_mode(i2c_port port);
void sda_output_mode(i2c_port port);

GPIO_InitTypeDef GPIO_InitStructure;

void init_i2c1(void){
	i2c_init(i2cPort1);
}
void i2c1_start(void){
	i2c_start(i2cPort1);
}
void i2c1_stop(void){
	i2c_stop(i2cPort1);
}
char i2c1_isReady(char deviceAddr){
	return i2c_isReady(i2cPort1, deviceAddr);
}
char i2c1_send_byte(char byte){
	return i2c_send_byte(i2cPort1, byte);
}
char i2c1_recv_byte(void){
	return i2c_recv_byte(i2cPort1);
}
void i2c1_send_ack(char ack){
	i2c_send_ack(i2cPort1, ack);
}
char i2c1_recv_ack(void){
	return i2c_recv_ack(i2cPort1);
}

void init_i2c2(void){
	i2c_init(i2cPort2);
}
void i2c2_start(void){
	i2c_start(i2cPort2);
}
void i2c2_stop(void){
	i2c_stop(i2cPort2);
}
char i2c2_isReady(char deviceAddr){
	return i2c_isReady(i2cPort2, deviceAddr);
}
char i2c2_send_byte(char byte){
	return i2c_send_byte(i2cPort2, byte);
}
char i2c2_recv_byte(void){
	return i2c_recv_byte(i2cPort2);
}
void i2c2_send_ack(char ack){
	i2c_send_ack(i2cPort2, ack);
}
char i2c2_recv_ack(void){
	return i2c_recv_ack(i2cPort2);
}


void set_scl(i2c_port port, u8 val){
	val ?GPIO_SetBits(port.scl_gpio, port.scl_pin)
		:GPIO_ResetBits(port.scl_gpio, port.scl_pin);
}

void set_sda(i2c_port port, u8 val){
	val ?GPIO_SetBits(port.sda_gpio, port.sda_pin)
		:GPIO_ResetBits(port.sda_gpio, port.sda_pin);
}

u8 get_sda(i2c_port port){
	return GPIO_ReadInputDataBit(port.sda_gpio, port.sda_pin);
}

void sda_input_mode(i2c_port port){
	GPIO_InitStructure.GPIO_Pin = port.sda_pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
	GPIO_Init(port.sda_gpio, &GPIO_InitStructure);
}

void sda_output_mode(i2c_port port){
	GPIO_InitStructure.GPIO_Pin = port.sda_pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port.sda_gpio, &GPIO_InitStructure);
}

void i2c_init(i2c_port port){
	RCC_APB2PeriphClockCmd(port.scl_gpio_clk, ENABLE);
	RCC_APB2PeriphClockCmd(port.sda_gpio_clk, ENABLE);
	GPIO_InitStructure.GPIO_Pin = port.scl_pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port.scl_gpio, &GPIO_InitStructure);
}

void i2c_start(i2c_port port){
	sda_output_mode(port);
	set_sda(port, 1);
	delay_us(US);
	set_scl(port, 1);
	delay_us(US);
	set_sda(port, 0);
	delay_us(US);
}

void i2c_stop(i2c_port port){
	sda_output_mode(port);
	set_sda(port, 0);
	set_scl(port, 1);
	delay_us(US);
	set_sda(port, 1);
	delay_us(US);
}

char i2c_isReady(i2c_port port, char deviceAddr){
	i2c_start(port);
	return i2c_send_byte(port, deviceAddr);
}
char i2c_send_byte(i2c_port port, char byte){
	char bitMask = 0x80;
	sda_output_mode(port);
	uint8_t i;
	for(i=0;i<8;i++)
	{
		set_scl(port, 0);
		set_sda(port, bitMask&byte);
		delay_us(US);
		set_scl(port, 1);
		delay_us(US);
		bitMask >>= 1;
	}
	set_scl(port, 0);
	return i2c_recv_ack(port);
}
char i2c_recv_byte(i2c_port port){
	char rs = 0;
	sda_input_mode(port);
	uint8_t i;
	for(i=0;i<8;i++)
	{
		set_scl(port, 1);
		delay_us(US);
		rs = (rs<<1)|get_sda(port);
		set_scl(port, 0);
		delay_us(US);
	}
	i2c_send_ack(port, 0);
	return rs;
}
void i2c_send_ack(i2c_port port, char ack){
	sda_output_mode(port);
	set_sda(port, ack);
	delay_us(US);
	set_scl(port, 1);
	delay_us(US);
	set_scl(port, 0);
	delay_us(US);
}
char i2c_recv_ack(i2c_port port){
	sda_input_mode(port);
	set_scl(port, 1);
	delay_us(US);
	char rs = get_sda(port);
	set_scl(port, 0);
	delay_us(US);
	return rs;
}
