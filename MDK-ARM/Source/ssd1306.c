#include "ssd1306.h"

void send_byte_stream(const u8* byteArr, u8 length, u8 type);
void send_char_4bit_height(u8 posX, u8 posY, const u8* byteArr, u8 length);
void set_cursor_pos(u8 posX, u8 posY);
void decode_arr(const u8* inArr, u8* outArr, u8 inLength);


void init_oled(){
  u8 byteSend[]={
    SET_DISP<<1,
    CLK_RATI,
    0x80,
    MUL_RATI,
    0x3f,
    DISP_OFFSET,
    0x00,
    START_LINE_0,
    CHARGE_PUMP,
    0x14,
    SEGMENT_REMAP<<1,
    SCAN_NORMAL,
    PIN_CONFIG,
    0x12,
    CONTRAST_CTR,
    0xcf,
    PRE_CHARGE_PERI,
    0xf1,
    DESEL_LEVEL,
    0x40,
    ENTIRE_DISP<<1,
    DISPLAY_MODE<<1,
    MEMO_MODE,
    MEMO_HORI,
    SET_DISP<<1|1
  };
  send_byte_stream(byteSend, sizeof(byteSend), CMD_STRE);
}

void oledClearScreen(){
  u8 i,j;
  set_cursor_pos(0,0);
  i2c1_start();
  i2c1_send_byte(ADDR_DEVICE<<1);
  i2c1_send_byte(DAT_STRE);
  for(i=0;i<8;i++)
    for(j=0;j<128;j++)
      i2c1_send_byte(0x00);
  i2c1_stop();
}

/*
* Function: oledPrintChar
* --------------------------
*                             0
*                             1
*      ____________           2
*   ___|___________|___       3: 0 -> 3: first byte 
*   |__|              | |     4 
*                  __|__|     5
*               ___|__|       6
*            ___|__|          7: 4 ->7: second byte
*   ________|__|_______       8
*   |_________________|       9
*                             10
*                             11: 8 -> 11: last byte
*
* Use thanhtaiFont :)) to display vietnamese character.
*
* character: 	character to display, get the integer value of character.
* posX: 			the left position of character to display in OLED.
* posY: 			the lowest postion of character to display in OLED.
*/
void oledPrintChar(u16 character, u8 posX, u8 posY){
	u8 byteSend[10];
	u8* test = bGetChar(character);
	decode_arr(test+5, byteSend, 5);  // cause 1 page only need 4 bit, \
												we need to covert 1 byte -> 2byte
	send_char_4bit_height(posX, posY-2, byteSend, 5);
	send_char_4bit_height(posX, posY-1, byteSend + 5, 5);
	
	decode_arr(test, byteSend, 5);
	send_char_4bit_height(posX, posY, byteSend, 5);
}

// width = 5
void oledPrintString(char* str, u8 posX, u8 posY, u8 width){
	if(!(*str)) return;
	u16 unicode;
	if((int)(*str)<128) unicode = *str;
	else if((int)(*str)< 0xcf) {
		unicode = utf8ToUnicode(*str, *(str+1),0);
		str+=1;
	} else {
		unicode = utf8ToUnicode(*str, *(str+1),*(str+2));
		str+=2;
	}
	oledPrintChar(unicode, posX, posY);
	if(unicode>64&&unicode<91)
		oledPrintString(str+1, posX+width+1, posY, width);
	else
		oledPrintString(str+1, posX+width, posY, width);
}

void oledPrintNumber(long number, u8 posX, u8 posY){
	char _sNum[21];
    sprintf(_sNum, "%ld", number);
	oledPrintString(_sNum, posX, posY, 5);
}

void oledPrintLargeNumber(long number, u8 posX, u8 posY){
	char _sNum[21];
    sprintf(_sNum, "%ld", number);
	oledPrintLargeString(_sNum, posX, posY, 13);
}

void oledPrintLargeChar(u16 character, u8 posX, u8 posY){
	const u8* byteSend = ssd1306NUMled_font13x20[character-48];
	u8 byteSend2[26];
	decode_arr(byteSend, byteSend2, 13);
	send_char_4bit_height(posX, posY-4, byteSend2, 13);
	send_char_4bit_height(posX, posY-3, byteSend2+13, 13);
	decode_arr(byteSend+13, byteSend2, 13);
	send_char_4bit_height(posX, posY-2, byteSend2, 13);
	send_char_4bit_height(posX, posY-1, byteSend2+13, 13);
	decode_arr(byteSend+26, byteSend2, 13);
	send_char_4bit_height(posX, posY, byteSend2, 13);
}
void oledPrintLargeString(char* str, u8 posX, u8 posY, u8 width){
	if(!(*str)) return;
	oledPrintLargeChar(*str, posX, posY);
	oledPrintLargeString(str+1, posX+width, posY, width);
}

void oledPrintFormatNumber(long number, u8 posX, u8 posY, char* formatStr){
	u8 numberLength = 1, tempNumber = number;
	while(tempNumber/10!=0) {
		numberLength++;
		tempNumber/=10;
	}
	for(int i=0;i<4;i++) oledPrintLargeChar('9'+1,posX+13*i,posY);
	oledPrintChar(' ',posX+13*4, posY);
	oledPrintLargeNumber(number, posX, posY);
	oledPrintString(formatStr, posX + 13*numberLength+2, posY, 6);
}

void oledPrintStatement(char* str, u8 posX, u8 posY){
	oledPrintString("                          ", posX, posY, 5);
	oledPrintString(str, posX, posY, 5);
}

void oledPrintIcon(u8 type, u8 posX, u8 posY){
	u8 byteSend[20];
	u8 *icon;
	u8 pinLength = 10;
	u8 bluetoothLength = 5;
	switch(type){
		case 5: //bluetooth
			icon=bluetoothIcon();
			decode_arr(icon, byteSend, bluetoothLength);
			send_char_4bit_height(posX, posY-1, byteSend, bluetoothLength);
			send_char_4bit_height(posX, posY, byteSend+bluetoothLength, bluetoothLength);
			break;
		case 6: //delete
			icon=bluetoothIconDelete();
			decode_arr(icon, byteSend, bluetoothLength);
			send_char_4bit_height(posX, posY-1, byteSend, bluetoothLength);
			send_char_4bit_height(posX, posY, byteSend+bluetoothLength, bluetoothLength);
			break;
		default:
			icon = pinIcon(type);
			decode_arr(icon, byteSend, pinLength);
			send_char_4bit_height(posX, posY-1, byteSend, pinLength);
			send_char_4bit_height(posX, posY, byteSend+pinLength, pinLength);
			break;
	}
	
	
}

/*
* Function: oledTest()
* --------------------
* Do what ever you want :))
*/
void oledTest(){
	oledPrintLargeNumber(123456789,0,7);

}

void set_cursor_pos(u8 posX, u8 posY){
  u8 byteSend[] = {
    COL_ADDR,
    posX, 127,
    ROW_ADDR,
    posY, 7
  };
  send_byte_stream(byteSend, sizeof(byteSend), CMD_STRE);
}

/*
* Function: send_byte_stream
* ------------------------------
* Send series of command or data to OLED.
* 
* byteArr: array of bytes to send in order.
* length: size of byte to send.
* type: command or data stream define in header.
*/
void send_byte_stream(const u8* byteArr, u8 length, u8 type){
  u8 i;
  i2c1_start();
  i2c1_send_byte(ADDR_DEVICE<<1);
  i2c1_send_byte(type); //command or data stream
  for(i=0;i<length;i++)
    i2c1_send_byte(byteArr[i]);
  i2c1_stop();
}

/*
* Function: send_char_4bit_height
* -----------------------------------
* Send 1 page = 4 led data height
*
* posX, posY : position of data to display
* byteArr	: in order of data to be display
* length: size of arr
*/
void send_char_4bit_height(u8 posX, u8 posY, const u8* byteArr, u8 length){
	set_cursor_pos(posX, posY);
	send_byte_stream(byteArr, length, DAT_STRE);
}

/*
* Function: decode_arr
* -----------------------
* Decode 1 byte character font to 2 byte character font, the series of first byte
* is then store at first half of output array, then the rest is store at the end.
* 
* inArr: input array from font.h.
* outArr: output array.
* inLenghth: size of inArr to convert.
*/
void decode_arr(const u8* inArr, u8* outArr, u8 inLength){
	u8 i, temp1, temp2;
	for(i=0; i<inLength; i++){
		temp1 = inArr[i]&0x0f;
		temp2 = inArr[i]>>4;
		outArr[i] = (temp1&1)+((temp1&2)<<1)+((temp1&4)<<2)+((temp1&8)<<3);
		outArr[i+inLength] = (temp2&1)+((temp2&2)<<1)+((temp2&4)<<2)+((temp2&8)<<3);
	}
}


