#ifndef __MAX30102_H
#define __MAX30102_H

#include "stm32f10x.h"
#include "i2c_std.h"
#include "delay.h"
#include <string.h>


#define	ADDR_DEVICE							0x57
//Define address of registers
#define ADDR_FIFO_WR_PTR				0x04
#define ADDR_OVF_COUNTER				0x05
#define ADDR_FIFO_RD_PTR				0x06
#define ADDR_FIFO_DATA					0x07
#define ADDR_FIFO_CONFIG				0x08
#define ADDR_MODE_CONFIG				0x09
#define ADDR_SPO2_CONFIG				0x0a
#define	ADDR_LED1_RED_PA				0x0c
#define	ADDR_LED2_IR_PA					0x0c
#define ADDR_MUL_SLOT12					0x11
#define ADDR_MUL_SLOT34					0x12
#define	ADDR_SHDN						0x09
//Define bit mask
//FIFO config register
#define FIFO_CONFIG_SMP_AVE_MASK				0x1f
#define FIFO_CONFIG_SMP_AVE_2						0x20
#define FIFO_CONFIG_SMP_AVE_4						0x40
#define FIFO_CONFIG_SMP_AVE_8						0x60
#define FIFO_CONFIG_SMP_AVE_16					0x80
#define FIFO_CONFIG_SMP_AVE_32					0xa0
#define FIFO_CONFIG_FIFO_ROLLOVER_MASK	0xef
#define FIFO_CONFIG_FIFO_ROLLOVER_EN		0x10
#define SHDN_MASK							0x7f
#define SHDN_WAKE_UP						0x00
#define SHDN_SHUT_DOWN						0x80
//mode config register
#define MODE_CONFIG_RESET_MASK					0xbf
#define MODE_CONFIG_RESET_EN						0x40
#define MODE_CONFIG_MODE_MASK						0xf8
#define MODE_CONFIG_MODE_HR							0x02
#define MODE_CONFIG_MODE_SPO2						0x03
#define MODE_CONFIG_MODE_MULTI					0x07
//SpO2 config register
#define SPO2_CONFIG_ADC_RGE_MASK				0x9f
#define SPO2_CONFIG_ADC_RGE_2048				0x00
#define SPO2_CONFIG_ADC_RGE_4096				0x02
#define SPO2_CONFIG_ADC_RGE_8192				0x04
#define SPO2_CONFIG_ADC_RGE_16384				0x06
#define SPO2_CONFIG_SR_MASK							0xe3
#define SPO2_CONFIG_SR_50								0x00
#define SPO2_CONFIG_SR_100							0x04
#define SPO2_CONFIG_SR_200							0x08
#define SPO2_CONFIG_SR_400							0x0c
#define SPO2_CONFIG_SR_800							0x10
#define SPO2_CONFIG_SR_1000							0x14
#define SPO2_CONFIG_SR_1600							0x18
#define SPO2_CONFIG_SR_3200							0x1c
#define SPO2_CONFIG_LED_PW_MASK					0xfc
#define SPO2_CONFIG_LED_PW_69  					0x00
#define SPO2_CONFIG_LED_PW_118 	 				0x01
#define SPO2_CONFIG_LED_PW_215 	 				0x02
#define SPO2_CONFIG_LED_PW_411 					0x03
//led pulse amplitude config
//interrip pin
#define INT_GPIO								GPIOB
#define INT_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define INT_Pin            			GPIO_Pin_11

//sample arr
extern uint32_t ledIRBuff[32];
extern uint32_t ledRedBuff[32];

char registerWrite(char addr, char byte);
char registerRead(char addr);
char registerBitWrite(char addr, char mask, char bit);
uint8_t max30102Setup(void);
void init_max30102(void);

// Configuration
void softReset(void);
void max30102ShutDown(void); 
void max30102WakeUp(void); 

// Data Collection



uint8_t getWritePointer(void);
uint8_t getReadPointer(void);

//
uint8_t readAllSampleAvailable(void);
uint32_t getRed(uint8_t index);
uint32_t getIR(uint8_t index);
uint8_t getReadPtr(void);
uint8_t getWritePtr(void);

#endif
