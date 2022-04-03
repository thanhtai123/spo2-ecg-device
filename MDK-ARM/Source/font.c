#include "font.h"

u16 specUnicode[]={
	250, //	ú
	249, //	ù
	361, //	ũ
	7911, //	ủ
	7909, //	ụ
	432, //	ư
	7913, //	ứ
	7915, //	ừ
	7919, //	ữ
	7917, //	ử
	7921, //	ự
	233, //	é
	232, //	è
	7869, //	ẽ
	7867, //	ẻ
	7865, //	ẹ
	234, //	ê
	7871, //	ế
	7873, //	ề
	7877, //	ễ
	7875, //	ể
	7879, //	ệ
	237, //	í
	236, //	ì
	297, //	ĩ
	7881, //	ỉ
	7883, //	ị
	253, //	ý
	7923, //	ỳ
	7929, //	ỹ
	7927, //	ỷ
	7925, //	ỵ
	224, //	à
	225, //	á
	227, //	ã
	7843, //	ả
	7841, //	ạ
	259, //	ă
	7855, //	ắ
	7857, //	ằ
	7861, //	ẵ
	7859, //	ẳ
	7863, //	ặ
	226, //	â
	7845, //	ấ
	7847, //	ầ
	7851, //	ẫ
	7849, //	ẩ
	7853, //	ậ
	243, //	ó
	242, //	ò
	245, //	õ
	7887, //	ỏ
	7885, //	ọ
	244, //	ô
	7889, //	ố
	7891, //	ồ
	7895, //	ỗ
	7893, //	ổ
	7897, //	ộ
	417, //	ơ
	7901, //	ờ
	7899, //	ớ
	7907, //	ợ
	7903, //	ở
	7905, //	ỡ
	273,   //đ
	272,   // Ð
};

void copyArr(const u8* inArr, u8* outArr, u8 size);
u32 utf8_to_unicode(u8 byte1, u8 byte2, u8 byte3);

u8* bGetChar(u16 unicode){
	static u8	rsChar[FONT_WIDTH];
	u16 indexTable=0;
	if(unicode < 128) indexTable = unicode-32;
	else {
		for(int i = 0; i<sizeof(specUnicode)/2;i++)
			if(unicode==specUnicode[i]) {
				indexTable = 127 - 32 + i;
				break;
			}
	}
	copyArr(
			ssd1306VNled_font5x12[indexTable],
			rsChar,
			FONT_WIDTH
		);
	return rsChar;
}

u8* bluetoothIcon(){
	static u8 icon[]={0x22, 0x14, 0x7f, 0x2a, 0x14};
	return icon;
}

u8* pinIcon(u8 level){
	static u8 icon[]={0x0c, 0x1e, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x3f, 0x00};
	u8 i;
	for(i=0;i<level;i++) icon[7-i]=0x2d;
	return icon;
}

void copyArr(const u8* inArr, u8* outArr, u8 size){
	u8 i;
	for(i=0; i<size; i++)
		outArr[i] = inArr[i];
}

u32 utf8ToUnicode(u8 byte1, u8 byte2, u8 byte3){
	u32 rs=0;
	if(byte1<128) rs = byte1;
	else if(byte1 < 224) {
		rs = byte1&0x1f;
		rs <<= 6;
		rs = rs | (byte2&0x3f);
	}
	else{
		rs = byte1&0x0f;
		rs <<= 6;
		rs = rs | (byte2&0x3f);
		rs <<= 6;
		rs = rs | (byte3&0x3f);
	}
	return rs;
}
