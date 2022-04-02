#ifndef __SSD1306_H
#define __SSD1306_H

#include "stm32f10x.h"
#include "i2c_std.h"
#include "font.h"
#include <stdio.h>
#include <string.h>

#define	ADDR_DEVICE							0x3c

#define CMD_STRE							0x00
#define CMD_BYTE							0x80
#define DAT_STRE							0x40
#define DAT_BYTE							0xc0
#define COL_ADDR                			0x21
#define ROW_ADDR                			0x22  //  know as page address
#define SET_DISP                			0x57  //  SET_DISP<<1|1 : ON, SET_DISP<<1 : OFF
#define CONTRAST_CTR            			0x81
#define MUL_RATI               				0xa8
#define CLK_RATI               				0xd5
#define DISP_OFFSET             			0xd3
#define START_LINE_0            			0x40
#define CHARGE_PUMP             			0x8d
#define ENABLE_CHARGE           			0x14
#define SEGMENT_REMAP         		  		0x50  // SEGMENT_REMAP<<1|1 : ON, SEGMENT_REMAP<<1 : OFF
#define SCAN_NORMAL             			0xc0
#define PIN_CONFIG              			0xda
#define CONFIG_ALT_DIS          			0x12
#define PRE_CHARGE_PERI         			0xd9
#define DESEL_LEVEL             			0xdb
#define ENTIRE_DISP             			0x52  // ENTIRE_DISP<<1|1 : ON, ENTIRE_DISP<<1 : OFF
#define DISPLAY_MODE            			0x53  // DISPLAY_MODE<<1|1 : top->bottom, DISPLAY_MODE<<1 : bottom->top
#define MEMO_MODE               			0x20
#define MEMO_HORI               			0x00
#define MEMO_VERT               			0x01
#define MEMO_PAGE               			0x10





void init_oled();
void oledClearScreen();
void oledPrintChar(u16 character, u8 posX, u8 posY);
void oledPrintString(char* str, u8 posX, u8 posY, u8 width);
void oledPrintIcon(u8 type, u8 posX, u8 posY);
void oledPrintNumber(long number, u8 posX, u8 posY);
void oledTest();

#endif
