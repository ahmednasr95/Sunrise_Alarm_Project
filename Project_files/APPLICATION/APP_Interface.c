
#include "APP_Private.h"
// extern SINT16_t Timing_array[];
// extern alarm_struct alarm_ptr_arr[NUM_OF_ALARMS];

ERROR_STATE app_init(){
	ERROR_STATE state_error = SUCCESS;
	ALL_LEDS_Initialize();
	alarm_scheduler_init();
	BUZZER_Initialize();
	LDR_init();
	LCD_Runable_Page();
	// 	LCD_Initialize();
	//
	//
	// 	Timing_Calculate();
	// 	Timing_Sort();
	// 	for(int i=0;i<3;i++){
	// 		LCD_Write_Number(Timing_array[i]);
	// 	}
	/*code init here*/
	return state_error;
}

ERROR_STATE app_main(){
	ERROR_STATE state_error = SUCCESS;
	LCD_First_Page();
	/*Main code here*/
	return state_error;
}
