#ifndef __I2C_STD_H
#define __I2C_STD_H

#include "stm32f10x.h"
#include "delay.h"

#define I2C1_SCL_GPIO								GPIOB
#define I2C1_SCL_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define I2C1_SCL_Pin            			GPIO_Pin_6

#define I2C1_SDA_GPIO								GPIOB
#define I2C1_SDA_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define I2C1_SDA_Pin            			GPIO_Pin_7

#define I2C2_SCL_GPIO								GPIOB
#define I2C2_SCL_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define I2C2_SCL_Pin            			GPIO_Pin_10//10

#define I2C2_SDA_GPIO								GPIOB
#define I2C2_SDA_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define I2C2_SDA_Pin            			GPIO_Pin_11//11

#define US													2

struct i2c_port
{
	GPIO_TypeDef *scl_gpio, *sda_gpio;
	u32 scl_gpio_clk, sda_gpio_clk;
	u16 scl_pin, sda_pin;
};

typedef struct i2c_port i2c_port;



void init_i2c1(void);
void i2c1_start(void);
void i2c1_stop(void);
char i2c1_isReady(char deviceAddr);
char i2c1_send_byte(char byte);
char i2c1_recv_byte(void);
void i2c1_send_ack(char ack);
char i2c1_recv_ack(void);

void init_i2c2(void);
void i2c2_start(void);
void i2c2_stop(void);
char i2c2_isReady(char deviceAddr);
char i2c2_send_byte(char byte);
char i2c2_recv_byte(void);
void i2c2_send_ack(char ack);
char i2c2_recv_ack(void);



#endif
