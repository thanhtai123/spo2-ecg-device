#include "i2c.h"

GPIO_InitTypeDef GPIO_InitStructure;

void sda_input_mode(void){
	RCC_APB2PeriphClockCmd(I2C_SDA_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = I2C_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
	GPIO_Init(I2C_SDA_GPIO, &GPIO_InitStructure);
}
void sda_output_mode(void){
	RCC_APB2PeriphClockCmd(I2C_SDA_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = I2C_SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(I2C_SDA_GPIO, &GPIO_InitStructure);
}

void i2c_init(void){
	
	RCC_APB2PeriphClockCmd(I2C_SCL_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = I2C_SCL_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(I2C_SCL_GPIO, &GPIO_InitStructure);
}
void i2c_start(void){
	sda_output_mode();
	SET_SDA(1);
	delay_us(US);
	SET_SCL(1);
	delay_us(US);
	SET_SDA(0);
	delay_us(US);
}
void i2c_stop(void){
	sda_output_mode();
	SET_SDA(0);
	SET_SCL(1);
	delay_us(US);
	SET_SDA(1);
	delay_us(US);
}
void i2c_send_ack(char ack){
	sda_output_mode();
	SET_SDA(ack);
	delay_us(US);
	SET_SCL(1);
	delay_us(US);
	SET_SCL(0);
	delay_us(US);
}
char i2c_recv_ack(void){
	sda_input_mode();
	SET_SCL(1);
	delay_us(US);
	char rs = GET_SDA();
	SET_SCL(0);
	delay_us(US);
	return rs;
}
char i2c_send_byte(char byte){
	char bitMask = 0x80;
	sda_output_mode();
	uint8_t i;
	for(i=0;i<8;i++)
	{
		SET_SCL(0);
		SET_SDA(bitMask&byte);
		delay_us(US);
		SET_SCL(1);
		delay_us(US);
		bitMask >>= 1;
	}
	SET_SCL(0);
	//delay_us(US);
	return i2c_recv_ack();
}

char i2c_recv_byte(void){
	char rs = 0;
	sda_input_mode();
	uint8_t i;
	for(i=0;i<8;i++)
	{
		SET_SCL(1);
		delay_us(US);
		rs = (rs<<1)|GET_SDA();
		SET_SCL(0);
		delay_us(US);
	}
	i2c_send_ack(0);
	return rs;
}
char i2c_isReady(char deviceAddr){
	i2c_start();
	return i2c_send_byte(deviceAddr<<1);
}
