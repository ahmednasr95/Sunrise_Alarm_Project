
#include "MAIN_PAGE.h"

extern UINT8_t	five_sec_timeout;
extern UINT16_t	Current_Time,TEN_Secs_Counter;
extern alarm_struct alarm_ptr_arr[NUM_OF_ALARMS];

bool Alarm_1_Fire_Flag = LOW,Alarm_2_Fire_Flag = LOW,Alarm_3_Fire_Flag = LOW;

ERROR_STATE LCD_Runable_Page(void)
{
	ERROR_STATE state_error = SUCCESS;

	LCD_LINE_position(LCD_LINE1,0);
	LCD_Write_String("SUNRISE ALARM CLOCK");
	
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("^_^ Welcome ^_^");
	
	LCD_LINE_position(LCD_LINE4,2);
	LCD_Write_String("BY: KYLIAN TECH");
	
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_LINE_position(LCD_LINE1,0);
	LCD_Write_String("Ali Embaby - 980");
	
	LCD_LINE_position(LCD_LINE2,0);
	LCD_Write_String("Seif Shebl - 894");
	
	LCD_LINE_position(LCD_LINE3,0);
	LCD_Write_String("Ahmed Nasr - 1069");
	
	LCD_LINE_position(LCD_LINE4,0);
	LCD_Write_String("Azza Saeed - 912");
	_delay_ms(2000);
	LCD_Clear();
	return state_error;
}


ERROR_STATE LCD_First_Page(void)
{
	ERROR_STATE state_error = SUCCESS;
	
	if(Alarm_1_Fire_Flag || Alarm_2_Fire_Flag || Alarm_3_Fire_Flag){
		Alarm_Action();
	}
	LCD_Clear();
	LCD_LINE_position(LCD_LINE1,0);
	LCD_Write_String("1-SET ALARM   |");
	LCD_LINE_position(LCD_LINE2,0);
	LCD_Write_String("2-CANCEL ALARM|");
	LCD_LINE_position(LCD_LINE3,0);
	LCD_Write_String("3-SHOW ALARMS |");
	
	LCD_Second_Page();
	return state_error;
}


ERROR_STATE LCD_Second_Page()
{	ERROR_STATE state_error = SUCCESS;
	

	bool button_1_val = FALSE;
	bool button_2_val = FALSE;
	bool button_3_val = FALSE;
	Display_Action_Buttons(Three_Buttons_No_X);
	LCD_Curser_OFF();
	while(!button_1_val && !button_2_val && !button_3_val){
		if(Alarm_1_Fire_Flag || Alarm_2_Fire_Flag || Alarm_3_Fire_Flag){
			break;
		}
		Nearest_Time_Display();
		BTN_pressed(DIO_PORTD, DIO_PIN7, &button_1_val);
		BTN_pressed(DIO_PORTD, DIO_PIN6, &button_2_val);
		BTN_pressed(DIO_PORTD, DIO_PIN5, &button_3_val);
	}
	LCD_Curser_ON();
	LCD_Clear();
	
	if(button_1_val){
		alarm_scheduler();
		/*in case button 2 is chosen*/
		} else if(button_2_val){
		LCD_Clear();
		LCD_Curser_OFF();
		Remove_Alarm();
		LCD_Curser_ON();
		/*in case button 3 is chosen*/
		} else if(button_3_val){
		LCD_Clear();
		LCD_Curser_OFF();
		if(Show_Alarms()){
			for(int i =0 ; i < 3 ;i++){
				Show_Alarms();
				_delay_ms(1000);
			}
			
		}else{
			/*do nothing*/
		}
		LCD_Curser_ON();
		/*to exit */
		}else{
		/*do nothing*/
	}

	return state_error;
}

ISR (TIMER1_COMP_1s){
	TEN_Secs_Counter++;
	five_sec_timeout++;
	if(Current_Time < 5940){
		Current_Time++;
		}else{
		Current_Time=0;
	}
	if(alarm_ptr_arr[0].Fire_Time == Current_Time){
		Alarm_1_Fire_Flag =HIGH;
	}
	if(alarm_ptr_arr[1].Fire_Time == Current_Time){
		Alarm_2_Fire_Flag =HIGH;
	}
	if(alarm_ptr_arr[2].Fire_Time == Current_Time){
		Alarm_3_Fire_Flag =HIGH;
	}
}