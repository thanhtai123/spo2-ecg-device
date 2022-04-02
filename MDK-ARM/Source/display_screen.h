#ifndef _DISPLAY_SCREEN_H_
#define _DISPLAY_SCREEN_H_

#include "ssd1306.h"
#include "delay.h"

#define HR_POSX	0
#define HR_POSY	4
#define SpO2_POSX	0
#define	SpO2_POSY	7
#define ECG_STR_DISP_POSX 0
#define ECG_STR_DISP_POSY 6


void intro_screen();
void device_status(u8 pinLevel, u8 bluetoothConn);
void ppg_mode_screen(u8 hr, u8 spo2);
void ecg_mode_screen(u8 bluetoothConn);




#endif 
