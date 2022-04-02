#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include "stm32f10x.h"

#define RELAY_OUTPUT_GPIO             		GPIOB
#define RELAY_OUTPUT_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define RELAY_OUTPUT_Pin            		GPIO_Pin_2

#define MOSFET_OUTPUT_GPIO             		GPIOA
#define MOSFET_OUTPUT_GPIO_CLK         		RCC_APB2Periph_GPIOA
#define MOSFET_OUTPUT_Pin            		GPIO_Pin_11

void init_output(void);
void RelayOutputOn(void);
void RelayOutputOff(void);
void MosfetOutputOn(void);
void MosfetOutputOff(void);
#endif 
