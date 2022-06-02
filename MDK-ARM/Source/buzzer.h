#ifndef __BUZZER_H
#define __BUZZER_H

#include "stm32f10x.h"
#include "delay.h"

#define BUZZER_GPIO						GPIOC
#define BUZZER_GPIO_CLK         		RCC_APB2Periph_GPIOC
#define BUZZER_Pin            			GPIO_Pin_13

void init_buzzer(void);
void buzzerOn(void);
void buzzerOff(void);



#endif
