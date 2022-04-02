#ifndef _TIMER_H_
#define _TIMER_H_

#include "stm32f10x.h"

extern unsigned char flag_timer;
extern unsigned char flag_timer4;
    
void init_timer(void);
void init_timer4(void);
void timer_isr(void);
void SetTimer_ms(int time);
void timer4_isr(void);
void SetTimer4_10ms(int time);

#endif 
