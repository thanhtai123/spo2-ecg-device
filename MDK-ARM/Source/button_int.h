#ifndef BUTTON_INT_H
#define BUTTON_INT_H

#include "stm32f10x.h"

#define BUTTON_INT2_GPIO					GPIOA
#define BUTTON_INT2_GPIO_CLK			    RCC_APB2Periph_GPIOA
#define BUTTON_INT2_Pin					    GPIO_Pin_15
#define INT2_PORT_SOURCE					GPIO_PortSourceGPIOA
#define INT2_PIN_SOURCE						GPIO_PinSource15
#define INT2_EXTI_LINE						EXTI_Line15
#define	INT2_IRQ_HANDLER					EXTI15_10_IRQn

#define BUTTON_INT1_GPIO					GPIOB
#define BUTTON_INT1_GPIO_CLK			    RCC_APB2Periph_GPIOB
#define BUTTON_INT1_Pin					    GPIO_Pin_15


void init_button_int(void);
void enable_buttion_int2(u8 val);

#endif
