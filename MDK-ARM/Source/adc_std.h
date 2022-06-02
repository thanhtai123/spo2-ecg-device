#ifndef __ADC_STD_H
#define __ADC_STD_H
#include "stm32f10x.h"

#define ADC_GPIO					GPIOB
#define ADC_GPIO_CLK         		RCC_APB2Periph_GPIOB
#define ADC_Pin            			GPIO_Pin_1

#define ADC1_DR_Address    ((uint32_t)0x4001244C)

extern uint16_t ADCConvertedValue1;

void init_adc(void);


#endif
