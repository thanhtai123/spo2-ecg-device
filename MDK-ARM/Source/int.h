#ifndef __INT_H
#define __INT_H
//interrip pin
#define INT_GPIO								GPIOA
#define INT_GPIO_CLK         		RCC_APB2Periph_GPIOA
#define INT_Pin            			GPIO_Pin_9
#define INT_PORT_SOURCE         GPIO_PortSourceGPIOA
#define INT_PIN_SOURCE          GPIO_PinSource9
#define INT_EXTI_LINE           EXTI_Line9
#define INT_IRQn                EXTI9_5_IRQn



#include "stm32f10x.h"
void gpio_int_init(void);
void EXTI9_5_Config(void);
void gpio_isr();

extern char flag_gpio;

#endif