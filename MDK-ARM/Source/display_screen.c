#include "display_screen.h"

void intro_screen(){
	oledPrintString("Nhóm 3 - Power on", 2, 3, 5);
	delay_ms(300);
}

void device_status(u8 pinLevel, u8 bluetoothConn){
	if(bluetoothConn) oledPrintIcon(5, 0, 1);
	if(pinLevel) oledPrintIcon(pinLevel, 80, 1);
}

void ppg_mode_screen(u8 hr, u8 spo2){
	char hrStr[] = "HR: ";
	u8 hrLength = 5*sizeof(hrStr)/sizeof(char);
	char spo2Str[] = "SpO2: ";
	u8 spo2Length = 5*sizeof(spo2Str)/sizeof(char);
	oledPrintString(hrStr, HR_POSX, HR_POSY, 5);
	oledPrintNumber(hr, HR_POSX+hrLength, HR_POSY);
	oledPrintString("bpm", HR_POSX+hrLength+4*5, HR_POSY,5);
	oledPrintString(spo2Str, SpO2_POSX, SpO2_POSY, 5);
	oledPrintNumber(spo2, SpO2_POSX+spo2Length, SpO2_POSY);
	oledPrintChar('%', SpO2_POSX+spo2Length+4*5, SpO2_POSY);
}

void ecg_mode_screen(u8 bluetoothConn){
	if(bluetoothConn) 
		oledPrintString(
			"Hiển thị trên diện thoại",
			ECG_STR_DISP_POSX,
			ECG_STR_DISP_POSY,
			5
		);
	else
		oledPrintString(
			"Kiểm tra bluetooth...",
			ECG_STR_DISP_POSX,
			ECG_STR_DISP_POSY,
			5
		);
}
