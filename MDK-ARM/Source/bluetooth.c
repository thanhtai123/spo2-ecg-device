#include "bluetooth.h"
#include <stdio.h>
#include <stdint.h>

uint8_t RXData_BT[BLE_RX_BUF];
uint8_t Update_BT = 0;
uint8_t inx_data_BT = 0;

void GPIO_Bluetooth_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(CONNECTED_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = CONNECTED_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
    GPIO_Init(CONNECTED_GPIO, &GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(PERIPHERAL_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = PERIPHERAL_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
    GPIO_Init(PERIPHERAL_GPIO, &GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(WAKEUP_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = WAKEUP_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
    GPIO_Init(WAKEUP_GPIO, &GPIO_InitStructure);
}

void Bluetooth_SendChar(char data)
{
	USART2_SendChar(data);
}

void Bluetooth_SendString(char * str)
{
	USART2_SendString(str);
}

u8 Bluetooth_getMsg(char* temp)
{
    int i;
    if(Update_BT) 
    {
        Update_BT = 0;
        for (i = 0; i <= inx_data_BT; i++){
            *(temp+i) = RXData_BT[i];
        }
        return 1;
    }
    else return 0;
}

uint8_t is_BLE_Connected(void)
{
	return GPIO_ReadInputDataBit(CONNECTED_GPIO, CONNECTED_Pin);
}

uint8_t is_BLE_Peripheral(void)
{
    return GPIO_ReadInputDataBit(PERIPHERAL_GPIO, PERIPHERAL_Pin);
}

void wake_up_Bluetooth(void)
{
    GPIO_ResetBits(WAKEUP_GPIO, WAKEUP_Pin);
    GPIO_SetBits(WAKEUP_GPIO, WAKEUP_Pin);
		GPIO_ResetBits(WAKEUP_GPIO, WAKEUP_Pin);
    GPIO_SetBits(WAKEUP_GPIO, WAKEUP_Pin);
}


void Bluetooth_SendNum(long num)
{
    USART2_SendNum(num);
}

void Bluetooth_Init(void)
{
    USART2_Init(38400);
    GPIO_Bluetooth_Init();
}

void Test_RX_receive(void)
{
    uint8_t rev[20];
    if ( Bluetooth_getMsg(&rev[0]) )
    {
        Bluetooth_SendString(rev);
        Bluetooth_SendString("\n");
    }
}
