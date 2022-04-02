#include "stm32f10x_it.h"
#include "timer.h"
#include "int.h"

void SysTick_Handler(void)
{
    timer_isr();
}

void EXTI9_5_IRQHandler(void)
{
#if defined (STM32F10X_HD_VL) || defined (STM32F10X_HD) || defined (STM32F10X_XL)
  if(EXTI_GetITStatus(EXTI_Line8) != RESET)
  {
    /* Toggle LED2 */
     STM_EVAL_LEDToggle(LED2);

    /* Clear the  EXTI line 8 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line8);
  }
#else
  if(EXTI_GetITStatus(EXTI_Line9) != RESET)
  {
    /* Toggle LED2 */
     gpio_isr();

    /* Clear the  EXTI line 9 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line9);
  }
#endif
}

