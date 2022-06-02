#ifndef __EEROM_H_
#define __EEROM_H_

#include "stm32f10x.h"
#include "delay.h"

#define EEROM_CS_GPIO             		GPIOB
#define EEROM_CS_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define EEROM_CS_Pin            			GPIO_Pin_6

#define EEROM_SCK_GPIO             		GPIOB
#define EEROM_SCK_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define EEROM_SCK_Pin            			GPIO_Pin_3

#define EEROM_SI_GPIO             		GPIOB
#define EEROM_SI_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define EEROM_SI_Pin            			GPIO_Pin_4

#define EEROM_SO_GPIO             		GPIOA//B
#define EEROM_SO_GPIO_CLK         		RCC_APB2Periph_GPIOA//B
#define EEROM_SO_Pin            			GPIO_Pin_1//5
#define EEROM_ID_OP 									0x9f


#define	EEROM_SCK(x)              		GPIO_WriteBit(EEROM_SCK_GPIO,EEROM_SCK_Pin,(x)?Bit_SET:Bit_RESET)
#define	EEROM_SI(x)              			GPIO_WriteBit(EEROM_SI_GPIO,EEROM_SI_Pin,(x)?Bit_SET:Bit_RESET)
#define	EEROM_CS(x)              			GPIO_WriteBit(EEROM_CS_GPIO,EEROM_CS_Pin,(x)?Bit_SET:Bit_RESET)
#define	EEROM_SO											GPIO_ReadInputDataBit(EEROM_SO_GPIO, EEROM_SO_Pin);										

#define EEROM_DELAY_US								1


void init_eerom(void);
void setDeviceID(u16 ID);
u16 getDeviceID(void);
u16 isEEROMHaveData(void);
u8 eerom_test();

#endif