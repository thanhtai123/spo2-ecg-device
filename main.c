#include "main.h"
#include <stdio.h>
#define NUM_TEST 100
#define TIMER_MS 100
#define NUM_DETECT (100/TIMER_MS)
#define THRESHOLD_SAMPLE	10000

//state machine
#define INTRO_STATE 		0
#define PPG_MODE_STATE 		1
#define PPG_DETECT_STATE 	2
#define PPG_STORE_STATE 	3
#define PPG_ESTIM_STATE 	4
#define ECG_MODE_STATE 		5

static u8 pinLevel, bluetoothConn, initState=0;
static u8 state = INTRO_STATE;

uint32_t irArr[NUM_TEST]={1150653, 1150540, 1150541, 1150577, 1150667, 1150657, 1150671, 1150673, 1150650, 1150673, 1150705, 1150733, 1150771, 1150766, 1150791, 1150768, 1150768, 1150796, 1150706, 1150630, 1150636, 1150700, 1150754, 1150758, 1150776, 1150748, 1150715, 1150745, 1150757, 1150775, 1150794, 1150792, 1150811, 1150780, 1150779, 1150762, 1150682, 1150650, 1150662, 1150697, 1150708, 1150741, 1150781, 1150698, 1150687, 1150694, 1150721, 1150755, 1150733, 1150734, 1150735, 1150742, 1150764, 1150721, 1150625, 1150550, 1150597, 1150661, 1150663, 1150680, 1150688, 1150640, 1150647, 1150649, 1150673, 1150680, 1150687, 1150714, 1150689, 1150687, 1150694, 1150673, 1150598, 1150483, 1150493, 1150559, 1150573, 1150632, 1150613, 1150598, 1150578, 1150604, 1150652, 1150642, 1150648, 1150662, 1150678, 1150710, 1150689, 1150700, 1150665, 1150560, 1150541, 1150571, 1150627, 1150637, 1150664, 1150665, 1150631, 1150635 
};
uint32_t redArr[NUM_TEST]={1434721, 1434338, 1434289, 1434471, 1434665, 1434749, 1434792, 1434756, 1434701, 1434719, 1434807, 1434888, 1434962, 1434985, 1435023, 1435016, 1435025, 1435043, 1434828, 1434525, 1434503, 1434705, 1434863, 1434937, 1434970, 1434896, 1434827, 1434871, 1434923, 1434996, 1435045, 1435074, 1435068, 1435070, 1435082, 1435012, 1434755, 1434558, 1434651, 1434770, 1434896, 1434975, 1434953, 1434864, 1434811, 1434877, 1434941, 1434975, 1435020, 1435029, 1435045, 1435057, 1435064, 1435023, 1434692, 1434440, 1434545, 1434724, 1434834, 1434896, 1434908, 1434807, 1434752, 1434811, 1434881, 1434941, 1434978, 1434988, 1434988, 1434981, 1435000, 1434972, 1434648, 1434337, 1434386, 1434579, 1434690, 1434772, 1434807, 1434730, 1434687, 1434734, 1434795, 1434883, 1434910, 1434956, 1434968, 1434993, 1435023, 1435029, 1434934, 1434582, 1434396, 1434587, 1434748, 1434845, 1434911, 1434877, 1434810, 1434811 
};
int testFlag = 0;

void testTimerInit(){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void testTimer()
{
	if(testFlag==0) GPIO_SetBits(GPIOA, GPIO_Pin_10);
	else GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	testFlag=(testFlag+1)%2;
}

void storeData(u16 timeMs){
	SetTimer_ms(timeMs);
	u8 sample_cnt=0;
	u8 flag_break=0;
	while (1)
	{
		while (!flag_timer);
		flag_timer = 0;
		u8 numTest = readAllSampleAvailable();
		for(u8 i=0;i<numTest;i++){
			if(sample_cnt==NUM_TEST){
				flag_break=1;
				break;
			}
			irArr[sample_cnt]=getIR(i);
			redArr[sample_cnt]=getRed(i);
			sample_cnt++;
		}
		if(flag_break) break;
	}
	SetTimer_ms(TIMER_MS);
}

u8 isValidData(u8 numData){
	for(u8 i=0;i<numData;i++)
		if(getRed(i)<THRESHOLD_SAMPLE) return 0;
	return 1;
}

void transData(){
	int i,test;
	for(i=0;i<100;i++){
		USART1_SendNum(i);
		USART1_SendString(", ");
	}
	USART1_SendString("\n\nred: ");
	for(i=0;i<NUM_TEST;i++){
		test=redArr[i];
		USART1_SendNum(test);
		USART1_SendString(", ");
	}
	USART1_SendString("\n\nir: ");
	for(i=0; i<NUM_TEST; i++){
		test=irArr[i];
		USART1_SendNum(test);
		USART1_SendString(", ");
	}
}

void transString(){
	USART1_SendString("\na ă â \n");
}

u8 mode_btn(){
	//return key_code[BUTTON_POWER_INDEX];
	static u16 pVal;
	u16 cVal = key_code[BUTTON_POWER_INDEX];
	u8 checkRt=0;
	if(!cVal) checkRt=1;
	else if(!pVal) checkRt=1;
	else if(cVal-pVal>5) checkRt=1;
	if(checkRt) {
		pVal=cVal;
		return cVal;
	}
	return 0;
	
}

u8 start_btn(){
	//return key_code[BUTTON_START_INDEX];
	static u16 pVal2;
	u16 cVal = key_code[BUTTON_START_INDEX];
	u8 checkRt=0;
	if(!cVal) checkRt=1;
	else if(!pVal2) checkRt=1;
	else if(cVal-pVal2>5) checkRt=1;
	if(checkRt) {
		pVal2=cVal;
		return cVal;
	}
	return 0;
	
}

u8 get_pin_level(){
	return 4;
}

u8 get_bluetooth_status(){
	return 1;
}

void change_state(u8 nState){
	state = nState;
	oledClearScreen();
	initState=0;
}

int main(void)
{
	uint16_t cnt = 0, cnt1=0;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	init_system();
	oledClearScreen();
	int32_t pn_spo2, pn_heart_rate;
	int8_t pch_spo2_valid, pch_hr_valid;
	
	u8 i,j,k;
	
	
	//PPG_DETECT_STATE
	u8 cnt_time_dt=NUM_DETECT+1;
	u8 cnt_sample, cnt_store=0;


	while (1)
	{
		while (!flag_timer);
		flag_timer = 0;
		cnt = 1 - cnt;
		cnt?DebugLedOn():DebugLedOff();
		scan_button();
		pinLevel = get_pin_level();
		bluetoothConn = get_bluetooth_status();
		if(state!=INTRO_STATE) device_status(pinLevel, bluetoothConn);
		switch(state){
			case INTRO_STATE:
				oledPrintString("Phiên bản demo v.1", 0, 7, 5);
				intro_screen();
				oledClearScreen();
				state = PPG_MODE_STATE;
				break;
			case PPG_MODE_STATE:
				if(!initState){
					//ppg_mode_screen(100, 100);
					oledPrintString("nhấn nút START để đo", 0, 7, 5);
					initState = 1;
				}
				if(mode_btn()) change_state(ECG_MODE_STATE);
				if(start_btn()) change_state(PPG_DETECT_STATE);
				break;
			case PPG_DETECT_STATE:
				if(!initState){
					initState = 1;
					max30102WakeUp();
					oledPrintString("đặt ngón tay vào cảm biến", 0, 7, 5);
					readAllSampleAvailable();
					break;
				}
				cnt_sample = readAllSampleAvailable();
				oledPrintString("                           ", 0, 7, 5);
				oledPrintNumber(cnt_store, 0, 7);
				cnt_store += cnt_sample;
				cnt_store *= isValidData(cnt_sample);
				if(cnt_store>10) change_state(PPG_STORE_STATE);
				if(mode_btn()) change_state(PPG_MODE_STATE);
				break;
			case PPG_STORE_STATE:
				if(!initState){
					initState = 1;
					cnt_store = 0;
					//max30102WakeUp();
					oledPrintString("đang lấy mẫu...", 0, 4, 5);
					oledPrintChar('%', 15, 7);
					readAllSampleAvailable();
					break;
				}
				cnt_sample = readAllSampleAvailable();
				oledPrintString("   ", 0, 7, 5);
				oledPrintNumber(cnt_store, 0, 7);
				
				//store sample to array of red and ir led
				for(i=0;i<cnt_sample;i++){
					j=i+cnt_store;
					irArr[j]=getIR(i);
					redArr[j]=getRed(i);
				}
				cnt_store += cnt_sample;
				cnt_store *= isValidData(cnt_sample);
				cnt_store = cnt_store>100?100:cnt_store;
				if(cnt_store>100) change_state(PPG_STORE_STATE);
				if(mode_btn()) change_state(PPG_MODE_STATE);
				break;
			case PPG_ESTIM_STATE:
				break;
			case ECG_MODE_STATE:
				if(!initState){
					ecg_mode_screen(bluetoothConn);
					initState = 1;
				}
				if(mode_btn())change_state(PPG_MODE_STATE);
				break;
			default:
				break;
		}
		//transString();
		//delay_ms(1000);
		/*storeData(100);
		//transData();
		maxim_heart_rate_and_oxygen_saturation(redArr,100,irArr,&pn_spo2,&pch_spo2_valid,&pn_heart_rate,&pch_hr_valid);
		if(pch_hr_valid==1) LcdPrintNumS(0,0,pn_heart_rate);
		else LcdPrintNumS(0,0,-1);
		if(pch_spo2_valid==1) LcdPrintNumS(1,5,pn_spo2);
		else LcdPrintNumS(1,5,-1);
		DisplayLcdScreen();
		LcdClearS();*/
		
		
	}

}


void init_system(void)
{
	init_timer();
	USART1_Init(9600);
	SetTimer_ms(TIMER_MS);
	init_lcd();
	init_i2c1();
	init_i2c2();
	init_oled();
	init_button();
	init_led();
	max30102Setup();//always behind i2c set up
	
}

