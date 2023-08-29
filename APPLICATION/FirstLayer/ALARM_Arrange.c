#include "ALARM_Arrange.h"

extern UINT8_t usr_def_alarms;
extern alarm_struct alarm_ptr_arr[NUM_OF_ALARMS];
extern bool Alarm_1_Fire_Flag ,Alarm_2_Fire_Flag ,Alarm_3_Fire_Flag ;
extern UINT16_t Current_Time;
/* Tested for king EMBO*/
ERROR_STATE Show_Alarms(){
	ERROR_STATE state_error = SUCCESS;
	if (usr_def_alarms == 0){
		LCD_Write_String("No Alarms Set");
		_delay_ms(2000);
		state_error = FAIL;
	}else{
		UINT8_t i=0;
		LCD_LINES Rows=LCD_LINE1;
		UINT8_t index=1;
		for (i=0;i<usr_def_alarms;i++){

			LCD_LINE_position(Rows,0);
			LCD_Write_Number(i+1);
			index++;
			LCD_LINE_position(Rows,1);
			LCD_Write_String("- ");
			UINT16_t remaining = alarm_ptr_arr[i].Fire_Time-Current_Time;
			printAlarm(((UINT8_t)remaining/60),((UINT8_t)remaining%60),Rows,2);
			Rows++;
			LCD_LINE_position(Rows,0);
		}
	}

	return state_error;
}
/* Tested for King EMBO*/
ERROR_STATE Remove_Alarm(){
	ERROR_STATE state_error = SUCCESS;
	
	bool button_1_val = FALSE;
	bool button_2_val = FALSE;
	bool button_3_val = FALSE;
	bool button_4_val = FALSE;

	if(Show_Alarms()){
		Display_Action_Buttons(All_Buttons);
		Check_Button_Update(&button_1_val,&button_2_val,&button_3_val,&button_4_val);
		LCD_Clear();
		
		if(button_1_val){
			erase(1);
			/*in case alarm 2 is chosen*/
			} else if(button_2_val){
			erase(2);
			/*in case alarm 3 is chosen*/
			} else if(button_3_val){
			erase(3);
			/*to exit the modify alarm page*/
			} else if(button_4_val){
			/*do nothing*/;
			} else{
			/*do nothing*/;
		}
	}else{
		state_error = FAIL;
	}
	
	return state_error;
	
}
void erase(UINT16_t reading){
	alarm_ptr_arr[reading-1].minutes=0;
	alarm_ptr_arr[reading-1].seconds=0;
	alarm_ptr_arr[reading-1].Fire_Time=0;
	UINT8_t shift=usr_def_alarms;
	if(reading==1){
		UINT8_t shift_index=0;
		while(shift!=1){
			alarm_ptr_arr[shift_index]=alarm_ptr_arr[shift_index+1];
			shift_index++;
			shift--;
		}
		alarm_ptr_arr[shift_index].minutes = 0;
		alarm_ptr_arr[shift_index].seconds = 0;
		alarm_ptr_arr[shift_index].Fire_Time=0;
	}
	else if(reading==2){
		if (usr_def_alarms==NUM_OF_ALARMS){
			alarm_ptr_arr[1]=alarm_ptr_arr[2];
			} else {
			/* Do Nothing*/
		}
	}
	else {
		/* Do Nothing*/
	}
	
	usr_def_alarms--;
	if(!Alarm_1_Fire_Flag && !Alarm_2_Fire_Flag && !Alarm_3_Fire_Flag){
		LCD_Write_String("ALARM DELETED");
		LCD_LINE_position(LCD_LINE2,0);
		LCD_Write_String("SUCCESSFULLY");
		_delay_ms(1500);
	}
	LCD_Clear();
}
