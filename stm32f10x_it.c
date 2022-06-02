#include "stm32f10x_it.h"
#include "timer.h"
#include "int.h"
u8 button_int_flag=0;
void SysTick_Handler(void)
{
    timer_isr();
}

void EXTI15_10_IRQHandler(void)
{
	button_int_flag=1;
	/* Clear the  EXTI line 0 pending bit */
	EXTI_ClearITPendingBit(EXTI_Line15);
}

u8 check_rcv_flag=0;
char rcv_buffer[100]; 
void USART1_IRQHandler(void)
{
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {
	rcv_buffer[check_rcv_flag++] = USART_ReceiveData(USART1);
	if(check_rcv_flag==100){
		USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
	}
  }
  
}
u8 check_rcv_flag2=0;
char rcv_buffer2[100]; 
void USART2_IRQHandler(void)
{
  if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
  {
	rcv_buffer2[check_rcv_flag2++] = USART_ReceiveData(USART2);
	if(check_rcv_flag2==100){
		USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
	}
  }
  
}


void EXTI2_IRQHandler(void){
	button_int_flag=1;
	/* Clear the  EXTI line 0 pending bit */
	EXTI_ClearITPendingBit(EXTI_Line15);
}

