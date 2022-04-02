#ifndef __I2C_H
#define __I2C_H

#include "stm32f10x.h"
#include "delay.h"

#define I2C_SCL_GPIO								GPIOB
#define I2C_SCL_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define I2C_SCL_Pin            			GPIO_Pin_10

#define I2C_SDA_GPIO								GPIOB
#define I2C_SDA_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define I2C_SDA_Pin            			GPIO_Pin_11

#define	SET_SCL(x)		(x)?GPIO_SetBits(I2C_SCL_GPIO, I2C_SCL_Pin):GPIO_ResetBits(I2C_SCL_GPIO, I2C_SCL_Pin)
#define	SET_SDA(x)		(x)?GPIO_SetBits(I2C_SDA_GPIO, I2C_SDA_Pin):GPIO_ResetBits(I2C_SDA_GPIO, I2C_SDA_Pin)
#define GET_SDA()			GPIO_ReadInputDataBit(I2C_SDA_GPIO, I2C_SDA_Pin)

#define US													2


#include "timer.h"

typedef uint8_t bool;


void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
char i2c_isReady(char deviceAddr);
char i2c_send_byte(char byte);
char i2c_recv_byte(void);
void i2c_send_ack(char ack);
char i2c_recv_ack(void);


#endif