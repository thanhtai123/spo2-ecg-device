#include "ad8232.h"

#define AD8232_READ_LO_PL	GPIO_ReadInputDataBit(AD8232_LOP_GPIO, AD8232_LOP_Pin)
#define AD8232_READ_LO_MI	GPIO_ReadInputDataBit(AD8232_LOM_GPIO, AD8232_LOM_Pin)
#define AD8232_SET_SDN(x)	GPIO_WriteBit(AD8232_SDN_GPIO,AD8232_SDN_Pin,(x)?Bit_SET:Bit_RESET)
void init_ad8232(void){
 GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(AD8232_LOP_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = AD8232_LOP_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(AD8232_LOP_GPIO, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(AD8232_LOM_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = AD8232_LOM_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(AD8232_LOM_GPIO, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(AD8232_SDN_GPIO_CLK, ENABLE);	 	
	GPIO_InitStructure.GPIO_Pin = AD8232_SDN_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(AD8232_SDN_GPIO, &GPIO_InitStructure);

}

void ad8232WakeUp(){
	AD8232_SET_SDN(1);
}

void ad8232SDN(){
	AD8232_SET_SDN(0);
}
u8 isECGReady(void){
	return AD8232_READ_LO_MI&&AD8232_READ_LO_PL;
}