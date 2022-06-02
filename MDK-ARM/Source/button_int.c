#include "button_int.h"


void init_button_int(void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
  /* Enable GPIOA clock */
  RCC_APB2PeriphClockCmd(BUTTON_INT2_GPIO_CLK, ENABLE);
  
  /* Configure PA.00 pin as input floating */
  GPIO_InitStructure.GPIO_Pin = BUTTON_INT2_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(BUTTON_INT2_GPIO, &GPIO_InitStructure);

  /* Enable AFIO clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

  /* Connect EXTI0 Line to PA.00 pin */
  GPIO_EXTILineConfig(INT2_PORT_SOURCE, INT2_PIN_SOURCE);

  /* Configure EXTI0 line */
  EXTI_InitStructure.EXTI_Line = INT2_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = INT2_IRQ_HANDLER;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	enable_buttion_int2(0);
}


void enable_buttion_int2(u8 val){
	val?NVIC_EnableIRQ(INT2_IRQ_HANDLER):NVIC_DisableIRQ(INT2_IRQ_HANDLER);
}