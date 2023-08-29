
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
		Alarm_1_Fire_Flag =LOW;
	}
	if(Alarm_2_Fire_Flag){
		erase(2);
		Alarm_2_Fire_Flag =LOW;
	}
	if(Alarm_3_Fire_Flag){
		erase(3);
		Alarm_3_Fire_Flag =LOW;
	}
}

void Nearest_Time_Display(void){
	printAlarm(((UINT8_t)(Current_Time/60)),((UINT8_t)(Current_Time%60)),LCD_LINE2,15);
	if(usr_def_alarms >0){
		bubbleSort(alarm_ptr_arr,usr_def_alarms);
		UINT16_t remaining = alarm_ptr_arr[0].Fire_Time-Current_Time;
		printAlarm(((UINT8_t)remaining/60),((UINT8_t)remaining%60),LCD_LINE4,15);
	}

}
ERROR_STATE Sort_Alarms(){
	alarm_struct temp;
	ERROR_STATE state_error = SUCCESS;
	if (usr_def_alarms<2){
		return state_error;
		} else {
		UINT8_t i=0,j=0,index=0,min_minutes=60,min_seconds=60;
		for (i=0;i<usr_def_alarms;i++){
			for (j=i;j<usr_def_alarms;j++){
				if (alarm_ptr_arr[j].minutes<min_minutes){
					min_minutes=alarm_ptr_arr[j].minutes;
					index=j;
				}
			}
			temp=alarm_ptr_arr[index];
			alarm_ptr_arr[index]=alarm_ptr_arr[i];
			alarm_ptr_arr[i]=temp;
			min_minutes=60;
		}
		index=0;
		if (alarm_ptr_arr[0].minutes==alarm_ptr_arr[1].minutes && alarm_ptr_arr[0].minutes==alarm_ptr_arr[2].minutes){
			for (i=0;i<usr_def_alarms;i++){
				for (j=i;j<usr_def_alarms;j++){
					if (alarm_ptr_arr[j].seconds<min_seconds){
						min_seconds=alarm_ptr_arr[j].seconds;
						index=j;
					}
				}
				temp=alarm_ptr_arr[index];
				alarm_ptr_arr[index]=alarm_ptr_arr[i];
				alarm_ptr_arr[i]=temp;
				min_seconds=60;
				
			}
		}
		else if (alarm_ptr_arr[0].minutes==alarm_ptr_arr[1].minutes){
			if (alarm_ptr_arr[0].seconds>alarm_ptr_arr[1].seconds){
				temp=alarm_ptr_arr[0];
				alarm_ptr_arr[0]=alarm_ptr_arr[1];
				alarm_ptr_arr[1]=temp;
				min_seconds=alarm_ptr_arr[i+1].seconds;
				
			}
		}
		else if (alarm_ptr_arr[1].minutes==alarm_ptr_arr[2].minutes){
			if (alarm_ptr_arr[1].seconds>alarm_ptr_arr[2].seconds){
				temp=alarm_ptr_arr[2];
				alarm_ptr_arr[2]=alarm_ptr_arr[1];
				alarm_ptr_arr[1]=temp;
				min_seconds=alarm_ptr_arr[i+1].seconds;
				
			}
		}
		
	}
	
	return state_error;
	
}

void swap(alarm_struct *a, alarm_struct *b) {
	alarm_struct temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(alarm_struct arr[], UINT16_t n) {
	for (UINT16_t i = 0; i < n - 1; i++) {
		for (UINT16_t j = 0; j < n - i - 1; j++) {
			if (arr[j].Fire_Time > arr[j + 1].Fire_Time) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}