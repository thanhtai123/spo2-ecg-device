#ifndef __FONT_H
#define __FONT_H

#include "stm32f10x.h"
#define FONT_WIDTH	10
#define FONT_HEIGHT	12

static const u8 ssd1306xled_font5x7 [][5]={
	{0x00, 0x00, 0x00, 0x00, 0x00}, // sp
	{0x00, 0x00, 0x5F, 0x00, 0x00}, // !
	{0x00, 0x03, 0x00, 0x03, 0x00}, // "
	{0x14, 0x3E, 0x14, 0x3E, 0x14}, // #
	{0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $
	{0x43, 0x33, 0x08, 0x66, 0x61}, // %
	{0x36, 0x49, 0x55, 0x22, 0x50}, // &
	{0x00, 0x05, 0x03, 0x00, 0x00}, // '
	{0x00, 0x1C, 0x22, 0x41, 0x00}, // (
	{0x00, 0x41, 0x22, 0x1C, 0x00}, // )
	{0x14, 0x08, 0x3E, 0x08, 0x14}, // *
	{0x08, 0x08, 0x3E, 0x08, 0x08}, // +
	{0x00, 0x50, 0x30, 0x00, 0x00}, // ,
	{0x08, 0x08, 0x08, 0x08, 0x08}, // -
	{0x00, 0x60, 0x60, 0x00, 0x00}, // .
	{0x20, 0x10, 0x08, 0x04, 0x02}, // /
	{0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
	{0x00, 0x04, 0x02, 0x7F, 0x00}, // 1
	{0x42, 0x61, 0x51, 0x49, 0x46}, // 2
	{0x22, 0x41, 0x49, 0x49, 0x36}, // 3
	{0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
	{0x27, 0x45, 0x45, 0x45, 0x39}, // 5
	{0x3E, 0x49, 0x49, 0x49, 0x32}, // 6
	{0x01, 0x01, 0x71, 0x09, 0x07}, // 7
	{0x36, 0x49, 0x49, 0x49, 0x36}, // 8
	{0x26, 0x49, 0x49, 0x49, 0x3E}, // 9
	{0x00, 0x36, 0x36, 0x00, 0x00}, // :
	{0x00, 0x56, 0x36, 0x00, 0x00}, // ;
	{0x08, 0x14, 0x22, 0x41, 0x00}, // <
	{0x14, 0x14, 0x14, 0x14, 0x14}, // =
	{0x00, 0x41, 0x22, 0x14, 0x08}, // >
	{0x02, 0x01, 0x51, 0x09, 0x06}, // ?
	{0x3E, 0x41, 0x59, 0x55, 0x5E}, // @
	{0x7E, 0x09, 0x09, 0x09, 0x7E}, // A
	{0x7F, 0x49, 0x49, 0x49, 0x36}, // B
	{0x3E, 0x41, 0x41, 0x41, 0x22}, // C
	{0x7F, 0x41, 0x41, 0x41, 0x3E}, // D
	{0x7F, 0x49, 0x49, 0x49, 0x41}, // E
	{0x7F, 0x09, 0x09, 0x09, 0x01}, // F
	{0x3E, 0x41, 0x41, 0x49, 0x3A}, // G
	{0x7F, 0x08, 0x08, 0x08, 0x7F}, // H
	{0x00, 0x41, 0x7F, 0x41, 0x00}, // I
	{0x30, 0x40, 0x40, 0x40, 0x3F}, // J
	{0x7F, 0x08, 0x14, 0x22, 0x41}, // K
	{0x7F, 0x40, 0x40, 0x40, 0x40}, // L
	{0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M
	{0x7F, 0x02, 0x04, 0x08, 0x7F}, // N
	{0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
	{0x7F, 0x09, 0x09, 0x09, 0x06}, // P
	{0x1E, 0x21, 0x21, 0x21, 0x5E}, // Q
	{0x7F, 0x09, 0x09, 0x09, 0x76}, // R
	{0x26, 0x49, 0x49, 0x49, 0x32}, // S
	{0x01, 0x01, 0x7F, 0x01, 0x01}, // T
	{0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
	{0x1F, 0x20, 0x40, 0x20, 0x1F}, // V
	{0x7F, 0x20, 0x10, 0x20, 0x7F}, // W
	{0x41, 0x22, 0x1C, 0x22, 0x41}, // X
	{0x07, 0x08, 0x70, 0x08, 0x07}, // Y
	{0x61, 0x51, 0x49, 0x45, 0x43}, // Z
	{0x00, 0x7F, 0x41, 0x00, 0x00}, // [
	{0x02, 0x04, 0x08, 0x10, 0x20}, // 55
	{0x00, 0x00, 0x41, 0x7F, 0x00}, // ]
	{0x04, 0x02, 0x01, 0x02, 0x04}, // ^
	{0x40, 0x40, 0x40, 0x40, 0x40}, // _
	{0x00, 0x01, 0x02, 0x04, 0x00}, // `
	//{0x20, 0x54, 0x54, 0x54, 0x78}, // a
	{0x40, 0xa9, 0xaa, 0xa8, 0xf0}, // a
	{0x7F, 0x44, 0x44, 0x44, 0x38}, // b
	{0x38, 0x44, 0x44, 0x44, 0x44}, // c
	{0x38, 0x44, 0x44, 0x44, 0x7F}, // d
	{0x38, 0x54, 0x54, 0x54, 0x18}, // e
	{0x04, 0x04, 0x7E, 0x05, 0x05}, // f
	{0x08, 0x54, 0x54, 0x54, 0x3C}, // g
	{0x7F, 0x08, 0x04, 0x04, 0x78}, // h
	{0x00, 0x44, 0x7D, 0x40, 0x00}, // i
	{0x20, 0x40, 0x44, 0x3D, 0x00}, // j
	{0x7F, 0x10, 0x28, 0x44, 0x00}, // k
	{0x00, 0x41, 0x7F, 0x40, 0x00}, // l
	{0x7C, 0x04, 0x78, 0x04, 0x78}, // m
	{0x7C, 0x08, 0x04, 0x04, 0x78}, // n
	{0x38, 0x44, 0x44, 0x44, 0x38}, // o
	{0x7C, 0x14, 0x14, 0x14, 0x08}, // p
	{0x08, 0x14, 0x14, 0x14, 0x7C}, // q
	{0x00, 0x7C, 0x08, 0x04, 0x04}, // r
	{0x48, 0x54, 0x54, 0x54, 0x20}, // s
	{0x04, 0x04, 0x3F, 0x44, 0x44}, // t
	{0x3C, 0x40, 0x40, 0x20, 0x7C}, // u
	{0x1C, 0x20, 0x40, 0x20, 0x1C}, // v
	{0x3C, 0x40, 0x30, 0x40, 0x3C}, // w
	{0x44, 0x28, 0x10, 0x28, 0x44}, // x
	{0x0C, 0x50, 0x50, 0x50, 0x3C}, // y
	{0x44, 0x64, 0x54, 0x4C, 0x44}, // z
	{0x00, 0x08, 0x36, 0x41, 0x41}, // {
	{0x00, 0x00, 0x7F, 0x00, 0x00}, // |
	{0x41, 0x41, 0x36, 0x08, 0x00}, // }
	{0x02, 0x01, 0x02, 0x04, 0x02}  // ~
};

static const u8 ssd1306VNled_font5x12 [][10] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // sp
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00,   // !
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00,  // "
	0x00, 0x01, 0x00, 0x01, 0x00, 0xa0, 0xf0, 0xa0, 0xf0, 0xa0,   // # 
	0x01, 0x01, 0x03, 0x01, 0x00, 0x20, 0x50, 0xf8, 0x50, 0x90,  // $
	0x02, 0x01, 0x00, 0x03, 0x03, 0x18, 0x98, 0x40, 0x30, 0x08,  // %
	0x01, 0x02, 0x02, 0x01, 0x02, 0xb0, 0x48, 0xa8, 0x10, 0x80,  // &
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x18, 0x00, 0x00,  //  '
	0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x00,  // (
	0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x08, 0x10, 0xe0, 0x00,  // )
	0x00, 0x00, 0x01, 0x00, 0x00, 0xa0, 0x40, 0xf0, 0x40, 0xa0,  // *
	0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x40, 0xf0, 0x40, 0x40,  // +
	0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,  //  ,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40,  // -
	0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // .
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10,  // /
	0x01, 0x02, 0x02, 0x02, 0x01, 0xf0, 0x88, 0x48, 0x28, 0xf0,  // 0
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x20, 0x10, 0xf8, 0x00,  // 1
	0x02, 0x03, 0x02, 0x02, 0x02, 0x10, 0x08, 0x88, 0x48, 0x30,  // 2
	0x01, 0x02, 0x02, 0x02, 0x01, 0x10, 0x08, 0x48, 0x48, 0xb0,  // 3
	0x00, 0x00, 0x00, 0x03, 0x00, 0xc0, 0xa0, 0x90, 0xf8, 0x80,  // 4
	0x01, 0x02, 0x02, 0x02, 0x01, 0x38, 0x28, 0x28, 0x28, 0xc8,  // 5
	0x01, 0x02, 0x02, 0x02, 0x01, 0xf0, 0x48, 0x48, 0x48, 0x90,  // 6
	0x00, 0x00, 0x03, 0x00, 0x00, 0x08, 0x08, 0x88, 0x48, 0x38,  // 7
	0x01, 0x02, 0x02, 0x02, 0x01, 0xb0, 0x48, 0x48, 0x48, 0xb0,  // 8
	0x01, 0x02, 0x02, 0x02, 0x01, 0x30, 0x48, 0x48, 0x48, 0xf0,  // 9
	0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0xb0, 0xb0, 0x00, 0x00,  // :
	0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0xb0, 0xb0, 0x00, 0x00,  // ;
	0x00, 0x00, 0x01, 0x02, 0x00, 0x40, 0xa0, 0x10, 0x08, 0x00,  // <
	0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0,  // =
	0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x08, 0x10, 0xa0, 0x40,  // >
	0x00, 0x00, 0x02, 0x00, 0x00, 0x10, 0x08, 0x88, 0x48, 0x30,  // ?
	0x01, 0x02, 0x02, 0x02, 0x02, 0xf0, 0x08, 0xc8, 0xa8, 0xf0,  // @
	0x03, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x48, 0x48, 0x48, 0xf0,  // A
	0x03, 0x02, 0x02, 0x02, 0x01, 0xf8, 0x48, 0x48, 0x48, 0xb0,  // B
	0x01, 0x02, 0x02, 0x02, 0x01, 0xf0, 0x08, 0x08, 0x08, 0x10,  // C
	0x03, 0x02, 0x02, 0x02, 0x01, 0xf8, 0x08, 0x08, 0x08, 0xf0,  // D
	0x03, 0x02, 0x02, 0x02, 0x02, 0xf8, 0x48, 0x48, 0x48, 0x08,  // E
	0x03, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x48, 0x48, 0x48, 0x08,  // F
	0x01, 0x02, 0x02, 0x02, 0x01, 0xf0, 0x08, 0x08, 0x48, 0xd0,  // G
	0x03, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x40, 0x40, 0x40, 0xf8,  // H
	0x00, 0x02, 0x03, 0x02, 0x00, 0x00, 0x08, 0xf8, 0x08, 0x00,  // I
	0x01, 0x02, 0x02, 0x02, 0x01, 0x80, 0x00, 0x00, 0x00, 0xf8,  // J
	0x03, 0x00, 0x00, 0x01, 0x02, 0xf8, 0x40, 0xa0, 0x10, 0x08,  // K
	0x03, 0x02, 0x02, 0x02, 0x02, 0xf8, 0x00, 0x00, 0x00, 0x00,  // L
	0x03, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x10, 0x60, 0x10, 0xf8,  // M
	0x03, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x10, 0x20, 0x40, 0xf8,  // N
	0x01, 0x02, 0x02, 0x02, 0x01, 0xf0, 0x08, 0x08, 0x08, 0xf0,  // O
	0x03, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x48, 0x48, 0x48, 0x30,  // P
	0x00, 0x01, 0x01, 0x01, 0x02, 0xf0, 0x08, 0x08, 0x08, 0xf0,  // Q
	0x03, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x48, 0x48, 0x48, 0xb0,  // R
	0x01, 0x02, 0x02, 0x02, 0x01, 0x30, 0x48, 0x48, 0x48, 0x90,  // S
	0x00, 0x00, 0x03, 0x00, 0x00, 0x08, 0x08, 0xf8, 0x08, 0x08,  // T
	0x01, 0x02, 0x02, 0x02, 0x01, 0xf8, 0x00, 0x00, 0x00, 0xf8,  // U
	0x00, 0x01, 0x02, 0x01, 0x00, 0xf8, 0x00, 0x00, 0x00, 0xf8,  // V
	0x03, 0x01, 0x00, 0x01, 0x03, 0xf8, 0x00, 0x80, 0x00, 0xf8,  // W
	0x02, 0x01, 0x00, 0x01, 0x02, 0x08, 0x10, 0xe0, 0x10, 0x08,  // X
	0x00, 0x00, 0x03, 0x00, 0x00, 0x38, 0x40, 0x80, 0x40, 0x38,  // Y
	0x03, 0x02, 0x02, 0x02, 0x02, 0x08, 0x88, 0x48, 0x28, 0x18,  // Z
	0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0xf8, 0x08, 0x00, 0x00,  // [
	0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x20, 0x40, 0x80, 0x00,  // 55
	0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x08, 0xf8, 0x00,  // ]
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x08, 0x10, 0x20,  // ^
	0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,  // _
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x20, 0x00,  // `
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa0, 0xa0, 0xa0, 0xc0,  // a
	0x03, 0x02, 0x02, 0x02, 0x01, 0xf8, 0x20, 0x20, 0x20, 0xc0,  // b
	0x01, 0x02, 0x02, 0x02, 0x02, 0xc0, 0x20, 0x20, 0x20, 0x20,  // c
	0x01, 0x02, 0x02, 0x02, 0x03, 0xc0, 0x20, 0x20, 0x20, 0xf8,  // d
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xc0,  // e
	0x00, 0x00, 0x03, 0x00, 0x00, 0x20, 0x20, 0xf0, 0x28, 0x28,  // f
	0x00, 0x05, 0x05, 0x05, 0x03, 0xc0, 0x20, 0x20, 0x20, 0xe0,  // g
	0x03, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x40, 0x20, 0x20, 0xc0,  // h
	0x00, 0x02, 0x03, 0x02, 0x00, 0x00, 0x20, 0xe8, 0x00, 0x00,  // i
	0x01, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x20, 0xe8, 0x00,  // j
	0x03, 0x00, 0x01, 0x02, 0x00, 0xf8, 0x80, 0x40, 0x20, 0x00,  // k
	0x00, 0x02, 0x03, 0x02, 0x00, 0x00, 0x08, 0xf8, 0x00, 0x00,  // l
	0x03, 0x00, 0x03, 0x00, 0x03, 0xe0, 0x20, 0xc0, 0x20, 0xc0,  // m
	0x03, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x40, 0x20, 0x20, 0xc0,  // n
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x20, 0x20, 0x20, 0xc0,  // o
	0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0xa0, 0xa0, 0x40,  // p
	0x00, 0x00, 0x00, 0x00, 0x03, 0x40, 0xa0, 0xa0, 0xa0, 0xe0,  // q
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0x20, 0x20,  // r
	0x02, 0x02, 0x02, 0x02, 0x01, 0x40, 0xa0, 0xa0, 0xa0, 0x00,  // s
	0x00, 0x00, 0x01, 0x02, 0x02, 0x20, 0x20, 0xf8, 0x20, 0x20,  // t
	0x01, 0x02, 0x02, 0x01, 0x03, 0xe0, 0x00, 0x00, 0x00, 0xe0,  // u
	0x00, 0x01, 0x02, 0x01, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0,  // v
	0x01, 0x02, 0x01, 0x02, 0x01, 0xe0, 0x00, 0x80, 0x00, 0xe0,  // w
	0x02, 0x01, 0x00, 0x01, 0x02, 0x20, 0x40, 0x80, 0x40, 0x20,  // x
	0x00, 0x05, 0x05, 0x05, 0x03, 0xe0, 0x00, 0x00, 0x00, 0xe0,  // y
	0x02, 0x03, 0x02, 0x02, 0x02, 0x20, 0x20, 0xa0, 0x60, 0x20,  // z
	0x00, 0x00, 0x01, 0x02, 0x02, 0x00, 0x40, 0xb0, 0x08, 0x08,  // (
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00,  // |
	0x02, 0x02, 0x01, 0x00, 0x00, 0x08, 0x08, 0xb0, 0x40, 0x00,  // )
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x10, 0x20, 0x10,  // ~
	0x01, 0x02, 0x02, 0x01, 0x03, 0xe0, 0x00, 0x08, 0x04, 0xe0,  // ú
	0x01, 0x02, 0x02, 0x01, 0x03, 0xe0, 0x04, 0x08, 0x00, 0xe0,  // ù
	0x01, 0x02, 0x02, 0x01, 0x03, 0xe4, 0x02, 0x04, 0x08, 0xe4,  // ũ
	0x01, 0x02, 0x02, 0x01, 0x03, 0xe0, 0x04, 0x0c, 0x00, 0xe0,  // ủ
	0x01, 0x02, 0x0a, 0x01, 0x03, 0xe0, 0x00, 0x00, 0x00, 0xe0,  // ụ
	0x01, 0x02, 0x02, 0x01, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x30,  // ư
	0x01, 0x02, 0x02, 0x01, 0x00, 0xe0, 0x00, 0x08, 0xe4, 0x30,  // ứ
	0x01, 0x02, 0x02, 0x01, 0x00, 0xe0, 0x04, 0x08, 0xe0, 0x30,  // ừ
	0x01, 0x02, 0x02, 0x01, 0x00, 0xe2, 0x01, 0x02, 0xe4, 0x34,  // ữ
	0x01, 0x02, 0x02, 0x01, 0x00, 0xe0, 0x04, 0x0c, 0xe0, 0x30,  // ử
	0x01, 0x02, 0x0a, 0x01, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x30,  // ự
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa0, 0xa8, 0xa4, 0xc0,  // é
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa4, 0xa8, 0xa0, 0xc0,  // è
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc4, 0xa2, 0xa4, 0xa8, 0xc4,  // ẽ
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa4, 0xac, 0xa0, 0xc0,  // ẻ
	0x01, 0x02, 0x0a, 0x02, 0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xc0,  // ẹ
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa8, 0xa4, 0xa8, 0xc0,  // ê
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc2, 0xa9, 0xa4, 0xa8, 0xc0,  // ế
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa8, 0xa4, 0xa9, 0xc2,  // ề
	0x03, 0x05, 0x05, 0x05, 0x01, 0x82, 0x51, 0x4a, 0x54, 0x82,  // ễ
	0x01, 0x02, 0x02, 0x02, 0x00, 0xc0, 0xa8, 0xa4, 0xa9, 0xc3,  // ể
	0x01, 0x02, 0x0a, 0x02, 0x00, 0xc0, 0xa8, 0xa4, 0xa8, 0xc0,  // ệ
	0x00, 0x02, 0x03, 0x02, 0x00, 0x00, 0x20, 0xe8, 0x04, 0x00,  // í
	0x00, 0x02, 0x03, 0x02, 0x00, 0x00, 0x24, 0xe8, 0x00, 0x00,  // ì
	0x00, 0x02, 0x03, 0x02, 0x00, 0x04, 0x22, 0xec, 0x08, 0x04,  // ĩ
	0x00, 0x02, 0x03, 0x02, 0x00, 0x00, 0x24, 0xec, 0x00, 0x00,  // ỉ
	0x00, 0x02, 0x0b, 0x02, 0x00, 0x00, 0x20, 0xe8, 0x00, 0x00,  // ị
	0x00, 0x05, 0x05, 0x05, 0x03, 0xe0, 0x00, 0x08, 0x04, 0xe0,  // ý
	0x00, 0x05, 0x05, 0x05, 0x03, 0xe0, 0x04, 0x08, 0x00, 0xe0,  // ỳ
	0x00, 0x05, 0x05, 0x05, 0x03, 0xe4, 0x02, 0x04, 0x08, 0xe4,  // ỹ
	0x00, 0x05, 0x05, 0x05, 0x03, 0xe0, 0x04, 0x0c, 0x00, 0xe0,  // ỷ
	0x00, 0x02, 0x0a, 0x02, 0x01, 0x70, 0x80, 0x80, 0x80, 0xf0,  // ỵ
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa0, 0xa4, 0xa8, 0xc0,  // à
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa0, 0xa8, 0xa4, 0xc0,  // á
	0x01, 0x02, 0x02, 0x02, 0x03, 0x04, 0xa2, 0xa4, 0xa8, 0xc4,  // ã
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa4, 0xac, 0xa0, 0xc0,  // ả
	0x01, 0x02, 0x0a, 0x02, 0x03, 0x00, 0xa0, 0xa0, 0xa0, 0xc0,  // ạ
	0x01, 0x02, 0x0a, 0x02, 0x03, 0x04, 0xa8, 0xa8, 0xa4, 0xc0,  // ă
	0x02, 0x05, 0x05, 0x05, 0x07, 0x08, 0x50, 0x52, 0x49, 0x80,  // ắ
	0x02, 0x05, 0x05, 0x05, 0x07, 0x08, 0x51, 0x52, 0x48, 0x80,  // ằ
	0x02, 0x05, 0x05, 0x05, 0x07, 0x0a, 0x51, 0x52, 0x4c, 0x82,  // ẵ
	0x02, 0x05, 0x05, 0x05, 0x07, 0x08, 0x51, 0x53, 0x48, 0x80,  // ẳ
	0x01, 0x02, 0x0a, 0x02, 0x01, 0x04, 0xa8, 0xa8, 0xa4, 0xc0,  // ặ
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa8, 0xa4, 0xa8, 0xc0,  // â
	0x01, 0x02, 0x02, 0x02, 0x03, 0x02, 0xa9, 0xa4, 0xa8, 0xc0,  // ấ
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa8, 0xa4, 0xa9, 0xc2,  // ầ
	0x02, 0x05, 0x05, 0x05, 0x07, 0x02, 0x51, 0x4a, 0x54, 0x82,  // ẫ
	0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0xa8, 0xa5, 0xab, 0xc0,  // ẩ
	0x01, 0x02, 0x0a, 0x02, 0x03, 0x00, 0xa8, 0xa4, 0xa8, 0xc0,  // ậ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x20, 0x28, 0x24, 0xc0,  // ó
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x20, 0x24, 0x28, 0xc0,  // ò
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc4, 0x22, 0x24, 0x28, 0xc4,  // õ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x24, 0x2c, 0x20, 0xc0,  // ỏ
	0x01, 0x02, 0x0a, 0x02, 0x01, 0xc0, 0x20, 0x20, 0x20, 0xc0,  // ọ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x28, 0x24, 0x28, 0xc0,  // ô
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc2, 0x29, 0x24, 0x28, 0xc0,  // ố
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x28, 0x24, 0x29, 0xc2,  // ồ
	0x03, 0x04, 0x04, 0x04, 0x03, 0x82, 0x51, 0x4a, 0x54, 0x82,  // ỗ
	0x03, 0x04, 0x04, 0x04, 0x03, 0x80, 0x50, 0x49, 0x53, 0x80,  // ổ
	0x01, 0x02, 0x0a, 0x02, 0x01, 0xc0, 0x28, 0x24, 0x28, 0xc0,  // ộ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x20, 0x20, 0x28, 0xd8,  // ơ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc2, 0x24, 0x20, 0x28, 0xd8,  // ờ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc0, 0x24, 0x22, 0x28, 0xd8,  // ớ
	0x01, 0x02, 0x0a, 0x02, 0x01, 0xc0, 0x20, 0x20, 0x28, 0xd8,  // ợ
	0x01, 0x02, 0x02, 0x02, 0x01, 0xc2, 0x26, 0x20, 0x28, 0xd8,  // ở
	0x03, 0x04, 0x04, 0x04, 0x03, 0x82, 0x41, 0x42, 0x54, 0xb2,  // ỡ
	0x01, 0x02, 0x02, 0x03, 0x02, 0x80, 0x40, 0x48, 0xfc, 0x08,  // đ
	0x00, 0x03, 0x02, 0x02, 0x01, 0x40, 0xf8, 0x48, 0x08, 0xf0,  // Ð
	
};
	

static const u8 ssd1306xled_font8x16[][16]={
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //   0
     0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x30, 0x00, 0x00, 0x00, // ! 1
     0x00, 0x10, 0x0C, 0x06, 0x10, 0x0C, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // " 2
     0x40, 0xC0, 0x78, 0x40, 0xC0, 0x78, 0x40, 0x00, 0x04, 0x3F, 0x04, 0x04, 0x3F, 0x04, 0x04, 0x00, // # 3
     0x00, 0x70, 0x88, 0xFC, 0x08, 0x30, 0x00, 0x00, 0x00, 0x18, 0x20, 0xFF, 0x21, 0x1E, 0x00, 0x00, // $ 4
     0xF0, 0x08, 0xF0, 0x00, 0xE0, 0x18, 0x00, 0x00, 0x00, 0x21, 0x1C, 0x03, 0x1E, 0x21, 0x1E, 0x00, // % 5
     0x00, 0xF0, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x1E, 0x21, 0x23, 0x24, 0x19, 0x27, 0x21, 0x10, // & 6
     0x10, 0x16, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ' 7
     0x00, 0x00, 0x00, 0xE0, 0x18, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x07, 0x18, 0x20, 0x40, 0x00, // ( 8
     0x00, 0x02, 0x04, 0x18, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x18, 0x07, 0x00, 0x00, 0x00, // ) 9
     0x40, 0x40, 0x80, 0xF0, 0x80, 0x40, 0x40, 0x00, 0x02, 0x02, 0x01, 0x0F, 0x01, 0x02, 0x02, 0x00, // * 10
     0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x1F, 0x01, 0x01, 0x01, 0x00, // + 11
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xB0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, // , 12
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, // - 13
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, // . 14
     0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x04, 0x00, 0x60, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, // / 15
     0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x10, 0x0F, 0x00, // 0 16
     0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, // 1 17
     0x00, 0x70, 0x08, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x30, 0x28, 0x24, 0x22, 0x21, 0x30, 0x00, // 2 18
     0x00, 0x30, 0x08, 0x88, 0x88, 0x48, 0x30, 0x00, 0x00, 0x18, 0x20, 0x20, 0x20, 0x11, 0x0E, 0x00, // 3 19
     0x00, 0x00, 0xC0, 0x20, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x07, 0x04, 0x24, 0x24, 0x3F, 0x24, 0x00, // 4 20
     0x00, 0xF8, 0x08, 0x88, 0x88, 0x08, 0x08, 0x00, 0x00, 0x19, 0x21, 0x20, 0x20, 0x11, 0x0E, 0x00, // 5 21
     0x00, 0xE0, 0x10, 0x88, 0x88, 0x18, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x20, 0x20, 0x11, 0x0E, 0x00, // 6 22
     0x00, 0x38, 0x08, 0x08, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, // 7 23
     0x00, 0x70, 0x88, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x1C, 0x22, 0x21, 0x21, 0x22, 0x1C, 0x00, // 8 24
     0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x00, 0x31, 0x22, 0x22, 0x11, 0x0F, 0x00, // 9 25
     0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, // : 26
     0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x00, 0x00, 0x00, 0x00, // ; 27
     0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, // < 28
     0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, // = 29
     0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, // > 30
     0x00, 0x70, 0x48, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x36, 0x01, 0x00, 0x00, // ? 31
     0xC0, 0x30, 0xC8, 0x28, 0xE8, 0x10, 0xE0, 0x00, 0x07, 0x18, 0x27, 0x24, 0x23, 0x14, 0x0B, 0x00, // @ 32
     0x00, 0x00, 0xC0, 0x38, 0xE0, 0x00, 0x00, 0x00, 0x20, 0x3C, 0x23, 0x02, 0x02, 0x27, 0x38, 0x20, // A 33
     0x08, 0xF8, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x11, 0x0E, 0x00, // B 34
     0xC0, 0x30, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x07, 0x18, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, // C 35
     0x08, 0xF8, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x10, 0x0F, 0x00, // D 36
     0x08, 0xF8, 0x88, 0x88, 0xE8, 0x08, 0x10, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x23, 0x20, 0x18, 0x00, // E 37
     0x08, 0xF8, 0x88, 0x88, 0xE8, 0x08, 0x10, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x03, 0x00, 0x00, 0x00, // F 38
     0xC0, 0x30, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x07, 0x18, 0x20, 0x20, 0x22, 0x1E, 0x02, 0x00, // G 39
     0x08, 0xF8, 0x08, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x20, 0x3F, 0x21, 0x01, 0x01, 0x21, 0x3F, 0x20, // H 40
     0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, // I 41
     0x00, 0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0xC0, 0x80, 0x80, 0x80, 0x7F, 0x00, 0x00, 0x00, // J 42
     0x08, 0xF8, 0x88, 0xC0, 0x28, 0x18, 0x08, 0x00, 0x20, 0x3F, 0x20, 0x01, 0x26, 0x38, 0x20, 0x00, // K 43
     0x08, 0xF8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x30, 0x00, // L 44
     0x08, 0xF8, 0xF8, 0x00, 0xF8, 0xF8, 0x08, 0x00, 0x20, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x20, 0x00, // M 45
     0x08, 0xF8, 0x30, 0xC0, 0x00, 0x08, 0xF8, 0x08, 0x20, 0x3F, 0x20, 0x00, 0x07, 0x18, 0x3F, 0x00, // N 46
     0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x20, 0x10, 0x0F, 0x00, // O 47
     0x08, 0xF8, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x20, 0x3F, 0x21, 0x01, 0x01, 0x01, 0x00, 0x00, // P 48
     0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x18, 0x24, 0x24, 0x38, 0x50, 0x4F, 0x00, // Q 49
     0x08, 0xF8, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x03, 0x0C, 0x30, 0x20, // R 50
     0x00, 0x70, 0x88, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x38, 0x20, 0x21, 0x21, 0x22, 0x1C, 0x00, // S 51
     0x18, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x18, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x00, 0x00, // T 52
     0x08, 0xF8, 0x08, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x20, 0x1F, 0x00, // U 53
     0x08, 0x78, 0x88, 0x00, 0x00, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x07, 0x38, 0x0E, 0x01, 0x00, 0x00, // V 54
     0xF8, 0x08, 0x00, 0xF8, 0x00, 0x08, 0xF8, 0x00, 0x03, 0x3C, 0x07, 0x00, 0x07, 0x3C, 0x03, 0x00, // W 55
     0x08, 0x18, 0x68, 0x80, 0x80, 0x68, 0x18, 0x08, 0x20, 0x30, 0x2C, 0x03, 0x03, 0x2C, 0x30, 0x20, // X 56
     0x08, 0x38, 0xC8, 0x00, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x00, 0x00, // Y 57
     0x10, 0x08, 0x08, 0x08, 0xC8, 0x38, 0x08, 0x00, 0x20, 0x38, 0x26, 0x21, 0x20, 0x20, 0x18, 0x00, // Z 58
     0x00, 0x00, 0x00, 0xFE, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x40, 0x40, 0x40, 0x00, // [ 59
     0x00, 0x0C, 0x30, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x38, 0xC0, 0x00, // \ 60
     0x00, 0x02, 0x02, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00, 0x00, // ] 61
     0x00, 0x00, 0x04, 0x02, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ^ 62
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, // _ 63
     0x00, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ` 64
     0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x19, 0x24, 0x22, 0x22, 0x22, 0x3F, 0x20, // a 65
     0x08, 0xF8, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x11, 0x20, 0x20, 0x11, 0x0E, 0x00, // b 66
     0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0x20, 0x11, 0x00, // c 67
     0x00, 0x00, 0x00, 0x80, 0x80, 0x88, 0xF8, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0x10, 0x3F, 0x20, // d 68
     0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x22, 0x22, 0x22, 0x22, 0x13, 0x00, // e 69
     0x00, 0x80, 0x80, 0xF0, 0x88, 0x88, 0x88, 0x18, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, // f 70
     0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x6B, 0x94, 0x94, 0x94, 0x93, 0x60, 0x00, // g 71
     0x08, 0xF8, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00, 0x00, 0x20, 0x3F, 0x20, // h 72
     0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, // i 73
     0x00, 0x00, 0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0xC0, 0x80, 0x80, 0x80, 0x7F, 0x00, 0x00, // j 74
     0x08, 0xF8, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x24, 0x02, 0x2D, 0x30, 0x20, 0x00, // k 75
     0x00, 0x08, 0x08, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, // l 76
     0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x3F, 0x20, 0x00, 0x3F, // m 77
     0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00, 0x00, 0x20, 0x3F, 0x20, // n 78
     0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x20, 0x1F, 0x00, // o 79
     0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xA1, 0x20, 0x20, 0x11, 0x0E, 0x00, // p 80
     0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0xA0, 0xFF, 0x80, // q 81
     0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x20, 0x3F, 0x21, 0x20, 0x00, 0x01, 0x00, // r 82
     0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x33, 0x24, 0x24, 0x24, 0x24, 0x19, 0x00, // s 83
     0x00, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x00, 0x00, // t 84
     0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x10, 0x3F, 0x20, // u 85
     0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x01, 0x0E, 0x30, 0x08, 0x06, 0x01, 0x00, // v 86
     0x80, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80, 0x80, 0x0F, 0x30, 0x0C, 0x03, 0x0C, 0x30, 0x0F, 0x00, // w 87
     0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x31, 0x2E, 0x0E, 0x31, 0x20, 0x00, // x 88
     0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x81, 0x8E, 0x70, 0x18, 0x06, 0x01, 0x00, // y 89
     0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 0x30, 0x2C, 0x22, 0x21, 0x30, 0x00, // z 90
     0x00, 0x00, 0x00, 0x00, 0x80, 0x7C, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x40, 0x40, // { 91
     0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, // | 92
     0x00, 0x02, 0x02, 0x7C, 0x80, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x3F, 0x00, 0x00, 0x00, 0x00, // } 93
     0x00, 0x06, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ~ 94
};

u32 utf8ToUnicode(u8 byte1, u8 byte2, u8 byte3);
u8* bGetChar(u16 unicode);
u8* bluetoothIcon();
u8* pinIcon(u8 level);
#endif
