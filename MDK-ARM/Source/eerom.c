#include "eerom.h"

void init_eerom(void){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(EEROM_CS_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = EEROM_CS_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EEROM_CS_GPIO, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(EEROM_SCK_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = EEROM_SCK_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EEROM_SCK_GPIO, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(EEROM_SI_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = EEROM_SI_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EEROM_SI_GPIO, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(EEROM_SO_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = EEROM_SO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;   
	GPIO_Init(EEROM_SO_GPIO, &GPIO_InitStructure);
	
	EEROM_SI(0);
	EEROM_SCK(0);
	EEROM_CS(1);
}

void eerom_send_byte(u8 byte){
	u8 mask = 0x80;
	u8 i, temp;
	//EEROM_CS(0);
	for(i=0; i<8; i++){
		temp = byte<<i;
		temp &= mask;
		EEROM_SI(temp);
		delay_us(EEROM_DELAY_US);
		EEROM_SCK(1);
		delay_us(EEROM_DELAY_US);
		EEROM_SCK(0);		
	}
	//delay_us(EEROM_DELAY_US);
	//EEROM_CS(1);
}

u8 eerom_recv_byte(void){
	u8 rs = 0;
	u8 i;
	for(i=0; i<8; i++){
		EEROM_SCK(1);
		delay_us(1);
		EEROM_SCK(0);
		delay_us(1);
		rs = (rs<<1) + EEROM_SO;
	}
	return rs;
}

u8 eerom_test(){
	u8 rs;
	EEROM_CS(0);
	delay_us(1);
	eerom_send_byte(EEROM_ID_OP);
	rs = eerom_recv_byte();
	EEROM_CS(1);
	return rs;
}

void setDeviceID(u16 ID){

}
u16 getDeviceID(void){
	return 1101;
}

u16 isEEROMHaveData(void){
	return 1;
}