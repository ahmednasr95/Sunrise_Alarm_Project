
#include "mbabbe.h"

UINT16_t Timing_array[3];
UINT16_t Current_Time=0,neg_counter=0,TEN_Secs_Counter=10;

extern UINT8_t usr_def_alarms;
extern alarm_struct alarm_ptr_arr[NUM_OF_ALARMS];
extern bool Alarm_1_Fire_Flag ,Alarm_2_Fire_Flag ,Alarm_3_Fire_Flag ;

void Alarm_Action(){
	UINT16_t reading=0;
	TEN_Secs_Counter=0;
	LDR_Read(&reading);
	LCD_Clear();
	LCD_LINE_position(LCD_LINE2,4);
	LCD_Write_String("!! ALARM !!");
	while (reading<550)
	{
		//printAlarm(((UINT8_t)Current_Time/60),((UINT8_t)Current_Time%60),LCD_LINE2,15);
		LDR_Read(&reading);
		if (TEN_Secs_Counter>=10){
			ALL_LEDS_ON();
			BUZZER_ON();
			TEN_Secs_Counter=10;
			} else {
			ALL_LEDS_dimming();
		}
	}
	BUZZER_OFF();
	ALL_LEDS_OFF();
	if(Alarm_1_Fire_Flag){
		erase(1);
	}
	if(Alarm_2_Fire_Flag){
		erase(2);
	}
	if(Alarm_3_Fire_Flag){
		erase(3);
	}
	Alarm_1_Fire_Flag =LOW;
	Alarm_2_Fire_Flag =LOW;
	Alarm_3_Fire_Flag =LOW;
}

void Nearest_Time_Display(void){
	printAlarm(((UINT8_t)(Current_Time/60)),((UINT8_t)(Current_Time%60)),LCD_LINE2,15);
	if(usr_def_alarms >0){
		customSort(alarm_ptr_arr,usr_def_alarms);
		UINT16_t remaining = alarm_ptr_arr[0].Fire_Time-Current_Time;
		printAlarm(((UINT8_t)remaining/60),((UINT8_t)remaining%60),LCD_LINE4,15);
	}

}

void swap(alarm_struct *a, alarm_struct *b) {
	alarm_struct temp = *a;
	*a = *b;
	*b = temp;
}

void customSort(alarm_struct arr[], UINT16_t n) {
	for (UINT16_t i = 0; i < n - 1; i++) {
		UINT16_t minIndex = i;
		for (UINT16_t j = i + 1; j < n; j++) {
			if (arr[j].Fire_Time != 0 &&
			(arr[minIndex].Fire_Time == 0 || arr[j].Fire_Time < arr[minIndex].Fire_Time)) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(&arr[i], &arr[minIndex]);
		}
	}
}