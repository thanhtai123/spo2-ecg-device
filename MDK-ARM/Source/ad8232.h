#ifndef __AD8232_H
#define __AD8232_H

#include "stm32f10x.h"

#define AD8232_LOP_GPIO             		GPIOA
#define AD8232_LOP_GPIO_CLK         		RCC_APB2Periph_GPIOA
#define AD8232_LOP_Pin            			GPIO_Pin_8

#define AD8232_LOM_GPIO             		GPIOA
#define AD8232_LOM_GPIO_CLK         		RCC_APB2Periph_GPIOA
#define AD8232_LOM_Pin            			GPIO_Pin_8

#define AD8232_SDN_GPIO             		GPIOA
#define AD8232_SDN_GPIO_CLK         		RCC_APB2Periph_GPIOA
#define AD8232_SDN_Pin            			GPIO_Pin_8


void init_ad8232(void);
u8 isECGReady(void);
void ad8232WakeUp();
void ad8232SDN();
#endif

