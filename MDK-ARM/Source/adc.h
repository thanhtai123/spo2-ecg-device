#ifndef _ADC_H_
#define _ADC_H_

#include "stm32f10x.h"

extern uint16_t adc_value;

void init_adc(void);
void get_adc(void);

#endif 
