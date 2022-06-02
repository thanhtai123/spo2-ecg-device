#include "buzzer.h"

void init_buzzer(){
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(BUZZER_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = BUZZER_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BUZZER_GPIO, &GPIO_InitStructure);
}

void buzzerOn(){
	GPIO_SetBits(BUZZER_GPIO, BUZZER_Pin);
}

void buzzerOff(){
	GPIO_ResetBits(BUZZER_GPIO, BUZZER_Pin);
}
