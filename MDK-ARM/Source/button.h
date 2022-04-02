#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "stm32f10x.h"

extern uint16_t key_code[2];

#define BUTTON_POWER_GPIO		    GPIOB
#define BUTTON_POWER_GPIO_CLK		RCC_APB2Periph_GPIOB
#define BUTTON_POWER_Pin				GPIO_Pin_2	

#define BUTTON_START_GPIO		    GPIOB
#define BUTTON_START_GPIO_CLK		RCC_APB2Periph_GPIOB
#define BUTTON_START_Pin				GPIO_Pin_3	

#define READ_POWER_BTN GPIO_ReadInputDataBit(BUTTON_POWER_GPIO, BUTTON_POWER_Pin)
#define READ_START_BTN GPIO_ReadInputDataBit(BUTTON_START_GPIO, BUTTON_START_Pin)

#define BUTTON_START_INDEX	1
#define BUTTON_POWER_INDEX	0

void init_button(void);
void scan_button(void);

#endif 
