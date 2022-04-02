#include "button.h"

uint16_t key_code[2] = {0,0};


void init_button(void){
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(BUTTON_POWER_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = BUTTON_POWER_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
    GPIO_Init(BUTTON_POWER_GPIO, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(BUTTON_START_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = BUTTON_START_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
    GPIO_Init(BUTTON_START_GPIO, &GPIO_InitStructure);
}

void scan_button(void)
{

	if (!READ_POWER_BTN)
		key_code[0] = key_code[0] + 1;
	else
		key_code[0] = 0;
	
	if (!READ_START_BTN)
            key_code[1] = key_code[1] + 1;
        else
            key_code[1] = 0;
  
}
