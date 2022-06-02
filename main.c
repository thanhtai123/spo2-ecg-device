#include "main.h"
#include <stdio.h>
#define NUM_TEST 100
#define TIMER_MS 100
#define	TIMER_CNT	100
#define NUM_DETECT (100/TIMER_MS)
#define THRESHOLD_SAMPLE	100000
#define	ECG_SAMPLE_RATE	100
#define POWER_CONTER		(500/TIMER_MS) // 5*100 mS


//state machine
#define INTRO_STATE 		0
#define PPG_MODE_STATE 		1
#define PPG_DETECT_STATE 	2
#define PPG_STORE_STATE 	3
#define PPG_ESTIM_STATE 	4
#define ECG_MODE_STATE 		5
#define ECG_START_STATE		6
#define OLED_STATEMENT_POSX	0
#define OLED_STATEMENT_POSY	7

//Bluetooth state machine
#define BT_SEND_DATA_STATE	0
#define BT_WAIT_ACK					1


static u8 pinLevel, bluetoothConn, initState=0, state_change_flag=1, spec_code=0;
static u8 state = INTRO_STATE, blt_state = BT_SEND_DATA_STATE;
uint16_t cnt = 0, cnt1=0, cnt_brk=1000, cnt_flag_timer=0;
int32_t pn_spo2, pn_heart_rate;
int8_t pch_spo2_valid, pch_hr_valid;
uint32_t adc_debug=0;
//PPG_DETECT_STATE
u8 cnt_time_dt=NUM_DETECT+1;
u8 cnt_sample, cnt_store=0, cnt_check=0;
//bluetooth state
u16 pkg_id;
u8 enable_btn=1, cnt_power=5, btn_inv=5;
u8 dan_cam_bien_ecg=1, ket_noi_ble=1;

uint32_t irArr[NUM_TEST]={1150653, 1150540, 1150541, 1150577, 1150667, 1150657, 1150671, 1150673, 1150650, 1150673, 1150705, 1150733, 1150771, 1150766, 1150791, 1150768, 1150768, 1150796, 1150706, 1150630, 1150636, 1150700, 1150754, 1150758, 1150776, 1150748, 1150715, 1150745, 1150757, 1150775, 1150794, 1150792, 1150811, 1150780, 1150779, 1150762, 1150682, 1150650, 1150662, 1150697, 1150708, 1150741, 1150781, 1150698, 1150687, 1150694, 1150721, 1150755, 1150733, 1150734, 1150735, 1150742, 1150764, 1150721, 1150625, 1150550, 1150597, 1150661, 1150663, 1150680, 1150688, 1150640, 1150647, 1150649, 1150673, 1150680, 1150687, 1150714, 1150689, 1150687, 1150694, 1150673, 1150598, 1150483, 1150493, 1150559, 1150573, 1150632, 1150613, 1150598, 1150578, 1150604, 1150652, 1150642, 1150648, 1150662, 1150678, 1150710, 1150689, 1150700, 1150665, 1150560, 1150541, 1150571, 1150627, 1150637, 1150664, 1150665, 1150631, 1150635 
};
uint32_t redArr[NUM_TEST]={1434721, 1434338, 1434289, 1434471, 1434665, 1434749, 1434792, 1434756, 1434701, 1434719, 1434807, 1434888, 1434962, 1434985, 1435023, 1435016, 1435025, 1435043, 1434828, 1434525, 1434503, 1434705, 1434863, 1434937, 1434970, 1434896, 1434827, 1434871, 1434923, 1434996, 1435045, 1435074, 1435068, 1435070, 1435082, 1435012, 1434755, 1434558, 1434651, 1434770, 1434896, 1434975, 1434953, 1434864, 1434811, 1434877, 1434941, 1434975, 1435020, 1435029, 1435045, 1435057, 1435064, 1435023, 1434692, 1434440, 1434545, 1434724, 1434834, 1434896, 1434908, 1434807, 1434752, 1434811, 1434881, 1434941, 1434978, 1434988, 1434988, 1434981, 1435000, 1434972, 1434648, 1434337, 1434386, 1434579, 1434690, 1434772, 1434807, 1434730, 1434687, 1434734, 1434795, 1434883, 1434910, 1434956, 1434968, 1434993, 1435023, 1435029, 1434934, 1434582, 1434396, 1434587, 1434748, 1434845, 1434911, 1434877, 1434810, 1434811 
};
uint16_t ecg_arr[100];
uint16_t ecg_buff[20];

u8 sizeOfNum(uint16_t num);
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

u8 isValidData(u8 numData, u8 endIndex){
	uint64_t mean=0, rms=0;
	
	for(u8 i=endIndex-numData;i<endIndex;i++){
		int64_t temp = redArr[i];
		if(temp<THRESHOLD_SAMPLE) return 0;
		mean += temp;
	}
	mean = mean/numData;
	//USART1_SendString("\nrms");
	//USART1_SendNum(mean);
	//USART1_SendString("\n");
	for(u8 i=endIndex-numData;i<endIndex;i++){
		int64_t temp = redArr[i];
		rms += (mean -temp)*(mean - temp);
	}
	//USART1_SendString("\nrms");
	//USART1_SendNum(rms);
	//USART1_SendString("\n");
	if(rms<30) return 0;
		
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

u8 mode_btn(){
	if(!enable_btn) return 0;
	static u16 pVal;
	u16 cVal = key_code[BUTTON_POWER_INDEX];
	u8 checkRt=0;
	if(!cVal) checkRt=1;
	else if(!pVal) checkRt=1;
	else if(cVal-pVal>2) checkRt=1;
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
	else if(cVal-pVal2>3) checkRt=1;
	if(checkRt) {
		pVal2=cVal;
		if(cVal){
			buzzerOn();
			
		}
			
		return cVal;
	}
	return 0;
	
}

u8 get_pin_level(){
	return 4;
}

void change_state(u8 nState){
	state = nState;
	oledClearScreen();
	initState=0;
	state_change_flag = 1;
	spec_code = 0;
	enable_btn = 0;
}
void doing_nothing(){};
uint16_t id_parse(char* str){
	uint16_t num = 0, iid=0;
	while(*str){
		num = num*10 + *str++ - 48;
	}
	return num;
}
void bluetooth_machine(){
	pkg_id = isEEROMHaveData();
	switch(blt_state){
		case BT_SEND_DATA_STATE:
			if(pkg_id) break;
			if(!bluetoothConn) break;
			Bluetooth_SendString("SEND_DATA:");
			Bluetooth_SendNum(pkg_id);
			blt_state = BT_WAIT_ACK;
			break;
		case BT_WAIT_ACK:
			if(!check_rcv_flag2) break;
			rcv_buffer2[check_rcv_flag2-1] = 0;
			check_rcv_flag2 = 0;
			if(id_parse(rcv_buffer2)!= pkg_id) goto blt_change_state_label;
			/**
			*@todo:
			* - Delete index0->pkg_id
			* - Reorder eerom data
			* - if it takes to long, we'll restart the initial of PPG_STORE_STATE to get correct data.
			*/
			blt_change_state_label:
			blt_state = BT_SEND_DATA_STATE;
			break;
		default:
			break;
	}
}

void transmitECG(){
	char strNum[120];
	u8 sizeNum=0;
	u16 totalIndex=0;
	for(u8 i=0; i<20; i++){
		sprintf(strNum+totalIndex, "%d", ecg_buff[i]);
		sizeNum = sizeOfNum(ecg_buff[i]);
		totalIndex+=sizeNum;
		strNum[totalIndex] = ':';
		totalIndex++;
		
	}
	strNum[totalIndex]=0;
	//strNum[totalIndex+1]=0;
	USART2_SendString(strNum);
	//delay_ms(100);
}

u8 sizeOfNum(uint16_t num){
	u8 rs = 1;
	while(num/10!=0){
		num = num/10;
		rs++;
	}
	return rs;
}
	
void main_thread(){
	u8 i,j,k;
	u8 max_set_up=1;
	pinLevel = get_pin_level();
	bluetoothConn = is_BLE_Connected();
	if(state!=INTRO_STATE) device_status(pinLevel, bluetoothConn);
	if(bluetoothConn){
		if(ket_noi_ble){
			ket_noi_ble = 0;
			buzzerOn();
		}
	} else {
		ket_noi_ble = 1;
	}
	if(state_change_flag){
		if(
			state == PPG_MODE_STATE ||
			state == PPG_STORE_STATE ||
			state == PPG_ESTIM_STATE
		) {
			oledPrintString("ppg", 110, 1, 5);
		}
		else oledPrintString("ecg", 110, 1, 5);
	}
	
	switch(state){
		case INTRO_STATE:
			if(!initState){
				initState = 1;
				state_change_flag = 0;
				cnt1 = 5;
			}
			cnt1--;
			//else cnt1 = 20;
			
			if(!cnt1) {
				change_state(PPG_MODE_STATE);
				init_oled();
				oledClearScreen();
				init_oled();
				init_button();
				init_led();
				init_buzzer();
				init_adc();
				oledClearScreen();
				init_button_int();
				Bluetooth_Init();
				max30102Setup();
				max30102WakeUp();
			}
			break;
		case PPG_MODE_STATE:
			if(!initState){
				initState = 1;
				state_change_flag = 0;
				max30102WakeUp();
			}
			//LED_CLK(1);
			oledPrintString(
				"Nhấn START đo HR/SpO2",
				OLED_STATEMENT_POSX, 
				OLED_STATEMENT_POSY,
				5
			);
			//LED_CLK(0);
			if(mode_btn()) change_state(ECG_START_STATE);
			if(start_btn()) change_state(PPG_STORE_STATE);
			break;
		case PPG_ESTIM_STATE:
			if(!initState){
				initState = 1;
				state_change_flag = 0;
				cnt1 = 5;
				maxim_heart_rate_and_oxygen_saturation(
					redArr,
					100,
					irArr,
					&pn_spo2,
					&pch_spo2_valid,
					&pn_heart_rate,
					&pch_hr_valid
				);
				/*USART1_SendString("\n");
				USART1_SendNum(pn_heart_rate);
				USART1_SendString("\n");
				USART1_SendNum(pn_spo2);*/
				if(pn_heart_rate==-999||pn_spo2==-999){
					change_state(PPG_STORE_STATE);
					break;
				}
				buzzerOn();
				USART2_SendString("h:");
				USART2_SendNum(pn_heart_rate);
				USART2_SendString(":");
				USART2_SendNum(pn_spo2);
				oledPrintFormatNumber(pn_heart_rate, 0, 7, "bpm");
				oledPrintFormatNumber(pn_spo2, 13*5, 7, "%");
				break;
			}
			if(!cnt1--){
				state = PPG_STORE_STATE;
				initState=0;
				state_change_flag = 1;
				spec_code = 1;
			}
			break;
		case PPG_STORE_STATE:
			if(!initState){
				initState = 1;
				state_change_flag = 0;
				cnt_store = 0;
				if(!spec_code){
					oledPrintString("Đang lấy mẫu ...", 0, 4, 5);
					oledPrintChar('%', 15, 7);
				}
				USART1_SendString("\nStart:\n");
				readAllSampleAvailable();
				break;
			}
			cnt_sample = readAllSampleAvailable();
			if(!spec_code){
				oledPrintString("   ", 0, 7, 5);
				oledPrintNumber(cnt_store, 0, 7);
			}
			//store sample to array of red and ir led
			for(i=0;i<cnt_sample;i++){
				j=i+cnt_store;
				if(j>=100) break;
				irArr[j]=getIR(i);
				redArr[j]=getRed(i);
				USART1_SendNum(redArr[j]);
				USART1_SendString(", ");
			}
			cnt_store += cnt_sample;
			cnt_check += cnt_sample;
			if(cnt_check>10){
				cnt_store *= isValidData(cnt_sample, cnt_store);
				cnt_check = 0;
			}
			cnt_store = cnt_store>100?100:cnt_store;
			if(cnt_store>=100) change_state(PPG_ESTIM_STATE);
			if(mode_btn()) change_state(PPG_MODE_STATE);
			//if(!cnt_store) USART1_SendString("\nRestart:\n");
			break;
		case ECG_START_STATE:
			//init state
			if(!initState){
				//ecg_mode_screen(bluetoothConn);
				state_change_flag = 0;
				oledPrintStatement("Nhấn START để đo ECG", OLED_STATEMENT_POSX, OLED_STATEMENT_POSY);
				enable_btn = 0;
				initState = 1;
				max30102ShutDown();
			}
			if(!bluetoothConn){
				wake_up_Bluetooth();
				goto ecg_start_btn_pressed_label;
			}
			if(start_btn()) change_state(ECG_MODE_STATE);
			ecg_start_btn_pressed_label:
			if(mode_btn())change_state(PPG_MODE_STATE);
			break;
		case ECG_MODE_STATE:
			//init state
			if(!initState){
				//ecg_mode_screen(bluetoothConn);
				state_change_flag = 0;
				initState = 1;
			}
			//checking the bluetooth connection
			if(!bluetoothConn){
				goto ecg_mode_btn_pressed_label;
			}
			//oledPrintStatement("Hiển thị trên màn hình!", OLED_STATEMENT_POSX, OLED_STATEMENT_POSY);
			oledPrintString("Đang lấy mẫu ...", 0, 4, 5);
			oledPrintChar('%', 15, 7);
			//enable interrupt and set timer 1ms
			enable_buttion_int2(1);
			button_int_flag=0;
			SetTimer_ms(10); //100hz
			cnt = 20;
			cnt1=0;
			//loop to sampling sample and transimit to bluetooth
			USART2_SendString("e:");
			cnt_brk = 1000;
			while(!button_int_flag){
				//LED_CLK(0);
				while(!flag_timer);
				get_adc();
				flag_timer=0;
				ecg_buff[20-cnt] = adc_value;
				cnt--;
				buzzerOff();
				//Bluetooth_SendNum(adc_value);
				if(!cnt){
					cnt = 20;
					buzzerOn();
					transmitECG();
					oledPrintString("   ", 0, 7, 5);
					oledPrintNumber(100-cnt_brk/10, 0, 7);
				}
				if(!cnt_brk--){
					break;
				}
			}
			USART2_SendString("n");
			//reset timer, disable interrupt
			SetTimer_ms(TIMER_MS);
			//buzzerOn();
			button_int_flag=0;
			enable_buttion_int2(0);
			change_state(ECG_START_STATE);
			goto ecg_mode_leave_state_label;
			ecg_mode_btn_pressed_label:
			if(mode_btn())change_state(ECG_START_STATE);
			ecg_mode_leave_state_label:
			break;
		default:
			break;
	}
}

void test_thread(){

	/*if(check_rcv_flag2){
		rcv_buffer2[check_rcv_flag2-1] = 0;
		Bluetooth_SendNum(
			id_parse(rcv_buffer2)
		);
		check_rcv_flag2=0;
	}*/
	//USART1_SendNum(adc_value);
	USART2_SendString("ecg:1234:3223:1234:3223:1234:3223:1234:3223:1234:3223:1234:3223:1234:3223:1234:3223:1234:3223:1234:9999:end");
	USART1_SendString("2");
	//oledPrintLargeString("hello world",0,0,5);
		
}

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	init_system();
	while (1)
	{
		while (!flag_timer);
		flag_timer = 0;
		cnt = 1-cnt;
		//cnt?LED_LAT(1):LED_LAT(0);
		scan_button();
		buzzerOff();
		main_thread();
		enable_btn = key_code[0]?enable_btn:1;
		
		//test_thread();
	}

}


void init_system(void)
{
	init_timer();
	SetTimer_ms(TIMER_MS);
	init_i2c1();
	init_i2c2();
	init_oled();
	init_button();
	init_led();
	init_buzzer();
	init_adc();
	oledClearScreen();
	init_button_int();
  Bluetooth_Init();
	USART2_Init(38400);
	USART1_Init(38400);
	max30102Setup();
	max30102WakeUp();
	LED_LAT(1);
}

