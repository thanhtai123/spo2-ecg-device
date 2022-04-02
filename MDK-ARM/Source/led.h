#ifndef _LED_H_
#define _LED_H_

#include "stm32f10x.h"

#define DEBUG_LED_GPIO             		GPIOA
#define DEBUG_LED_GPIO_CLK         		RCC_APB2Periph_GPIOA
#define DEBUG_LED_Pin            		GPIO_Pin_10

#define LED_CLK_GPIO					GPIOB
#define LED_CLK_GPIO_CLK			    RCC_APB2Periph_GPIOB
#define LED_CLK_Pin					    GPIO_Pin_15							

#define LED_LAT_GPIO					GPIOB
#define LED_LAT_GPIO_CLK			    RCC_APB2Periph_GPIOB
#define LED_LAT_Pin					    GPIO_Pin_13	

#define LED_SDO_GPIO					GPIOB
#define LED_SDO_GPIO_CLK			    RCC_APB2Periph_GPIOB
#define LED_SDO_Pin					    GPIO_Pin_14	

#define	LED_CLK(x)              GPIO_WriteBit(LED_CLK_GPIO,LED_CLK_Pin,(x)?Bit_SET:Bit_RESET)
#define	LED_LAT(x)              GPIO_WriteBit(LED_LAT_GPIO,LED_LAT_Pin,(x)?Bit_SET:Bit_RESET)
#define	LED_SDO(x)              GPIO_WriteBit(LED_SDO_GPIO,LED_SDO_Pin,(x)?Bit_SET:Bit_RESET)

void init_led(void);
void DebugLedOn(void);
void DebugLedOff(void);
void BlinkDebugLed(void);
void LedTurnOn(uint8_t index);
void LedTurnOff(uint8_t index);


#endif 
