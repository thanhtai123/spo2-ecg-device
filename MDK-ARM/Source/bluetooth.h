#ifndef __BLUETOOTH_H_
#define __BLUETOOTH_H_

#include "stm32f10x.h"
#include "uart.h"
#include <stdint.h>
#include <stdbool.h>

#define CONNECTED_GPIO          GPIOA
#define CONNECTED_GPIO_CLK      RCC_APB2Periph_GPIOA
#define CONNECTED_Pin           GPIO_Pin_11

#define PERIPHERAL_GPIO         GPIOA
#define PERIPHERAL_GPIO_CLK     RCC_APB2Periph_GPIOA
#define PERIPHERAL_Pin          GPIO_Pin_12

#define WAKEUP_GPIO             GPIOB
#define WAKEUP_GPIO_CLK         RCC_APB2Periph_GPIOB
#define WAKEUP_Pin              GPIO_Pin_14

#define BLE_RX_BUF              20

void Bluetooth_Init(void);
void Bluetooth_SendChar(char data);
void Bluetooth_SendString(char * data);
void Bluetooth_SendNum(long num);
void USART2_IRQ_Handler(void);
u8 Bluetooth_getMsg(char* temp);
uint8_t is_BLE_Connected(void);
uint8_t is_BLE_Peripheral(void);
void wake_up_Bluetooth(void);
void Test_RX_receive(void);

#endif 

