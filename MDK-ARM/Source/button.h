#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "stm32f10x.h"

extern uint16_t key_code[2];

#define BUTTON_POWER_GPIO		    GPIOA
#define BUTTON_POWER_GPIO_CLK		RCC_APB2Periph_GPIOA
#define BUTTON_POWER_Pin				GPIO_Pin_15	

#define BUTTON_START_GPIO		    GPIOC
#define BUTTON_START_GPIO_CLK		RCC_APB2Periph_GPIOC
#define BUTTON_START_Pin				GPIO_Pin_14

#define POWER_EN_GPIO		    GPIOB
#define POWER_EN_GPIO_CLK		RCC_APB2Periph_GPIOB
#define POWER_EN_Pin				GPIO_Pin_15

#define READ_POWER_BTN GPIO_ReadInputDataBit(BUTTON_POWER_GPIO, BUTTON_POWER_Pin)
#define READ_START_BTN GPIO_ReadInputDataBit(BUTTON_START_GPIO, BUTTON_START_Pin)
#define	POWER_ENABLE(x)         GPIO_WriteBit(POWER_EN_GPIO,POWER_EN_Pin,(x)?Bit_SET:Bit_RESET)

#define BUTTON_START_INDEX	1
#define BUTTON_POWER_INDEX	0



void init_button(void);
void scan_button(void);


#endif 
