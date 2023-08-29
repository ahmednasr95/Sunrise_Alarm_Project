

#include "ahmed_nasr.h"

UINT8_t five_sec_timeout = 0;

UINT8_t usr_def_alarms = 0;
alarm_struct alarm_ptr_arr[NUM_OF_ALARMS];

extern UINT16_t	Current_Time;

/*
*	Inputs:	addresses of tens and ones units of both minutes and seconds.
*	Outputs: either success or fail.
*	Description: The function modifies the alarm value and outputs the modified value to the LCD.
*/
ERROR_STATE modifyAlarm(UINT8_t* minutes_tens, UINT8_t* minutes_ones, UINT8_t* seconds_tens, UINT8_t* seconds_ones){
	
	/*Local Initializations*/
	bool move_left = 0;
	bool increment = 0;
	bool decrement = 0;
	bool move_right = 0;
	static UINT8_t cursor_loc = MODIFY_ALARM_CURSOR_LOC;
	ERROR_STATE state_error = SUCCESS;
	/************************************************************************/
	/*if the move left button is pressed...*/
	BTN_pressed(DIO_PORTD, DIO_PIN3, &move_left);
	if(move_left){
		/*modify cursor location*/
		cursor_loc++;
		/*to avoid writing over the colon*/
		if(COLON_LOC == cursor_loc){
			cursor_loc = SECONDS_TENS_LOC;
			/*to get back to the  start location*/
			} else if((SECONDS_ONES_LOC + 1) == cursor_loc){
			cursor_loc = MINUTES_TENS_LOC;
			} else{
			/*do nothing*/;
		}
		/*move the cursor*/
		LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
		five_sec_timeout = 0;
		}else{
		/*do nothing*/;
	}
	/************************************************************************/
	/*if the increment button is pressed...*/
	BTN_pressed(DIO_PORTD, DIO_PIN5, &increment);
	if(increment){
		/*check on which digit the cursor is standing*/
		switch(cursor_loc){
			/********************first case*********************/
			case MINUTES_TENS_LOC:
			/*to keep values between 0 and 9*/
			if(8 < *minutes_tens){
				*minutes_tens = 0;
				}else{
				(*minutes_tens)++;
			}
			LCD_Write_Number(*minutes_tens);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************second case*********************/
			case MINUTES_ONES_LOC:
			/*to keep values between 0 and 9*/
			if(8 < *minutes_ones){
				*minutes_ones = 0;
				/*this increments the tens digit when the ones digit reaches 9*/
				if(8 < *minutes_tens){
					*minutes_tens = 0;
					}else{
					(*minutes_tens)++;
				}
				/*update the tens digit*/
				LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc - 1);
				LCD_Write_Number(*minutes_tens);
				}else{
				(*minutes_ones)++;
			}
			LCD_Write_Number(*minutes_ones);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************third case*********************/
			case SECONDS_TENS_LOC:
			/*to keep values between 0 and 5*/
			if(4 < *seconds_tens){
				*seconds_tens = 0;
				}else{
				(*seconds_tens)++;
			}
			LCD_Write_Number(*seconds_tens);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************fourth case*********************/
			case SECONDS_ONES_LOC:
			/*to keep values between 0 and 9*/
			if(8 < *seconds_ones){
				*seconds_ones = 0;
				/*this increments the tens digit when the ones digit reaches 9*/
				if(4 < *seconds_tens){
					*seconds_tens = 0;
					}else{
					(*seconds_tens)++;
				}
				/*update the tens digit*/
				LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc - 1);
				LCD_Write_Number(*seconds_tens);
				}else{
				(*seconds_ones)++;
			}
			LCD_Write_Number(*seconds_ones);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************default*********************/
			default:
			break;
		}
		five_sec_timeout = 0;
		}else{
		/*do nothing*/;
	}
	/************************************************************************/
	/*if the decrement button is pressed...*/
	BTN_pressed(DIO_PORTD, DIO_PIN6, &decrement);
	if(decrement){
		/*check on which digit the cursor is standing*/
		switch(cursor_loc){
			/********************first case*********************/
			case MINUTES_TENS_LOC:
			/*to keep values between 0 and 9*/
			if(0 == *minutes_tens){
				*minutes_tens = 9;
				}else{
				(*minutes_tens)--;
			}
			LCD_Write_Number(*minutes_tens);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************second case*********************/
			case MINUTES_ONES_LOC:
			/*to keep values between 0 and 9*/
			if(0 == *minutes_ones){
				*minutes_ones = 9;
				/*this decrements the tens digit when the ones digit reaches 0*/
				if(0 == *minutes_tens){
					*minutes_tens = 9;
					}else{
					(*minutes_tens)--;
				}
				/*update the tens digit*/
				LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc - 1);
				LCD_Write_Number(*minutes_tens);
				}else{
				(*minutes_ones)--;
			}
			LCD_Write_Number(*minutes_ones);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************third case*********************/
			case SECONDS_TENS_LOC:
			/*to keep values between 0 and 5*/
			if(0 == *seconds_tens){
				*seconds_tens = 5;
				}else{
				(*seconds_tens)--;
			}
			LCD_Write_Number(*seconds_tens);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************fourth case*********************/
			case SECONDS_ONES_LOC:
			/*to keep values between 0 and 9*/
			if(0 == *seconds_ones){
				*seconds_ones = 9;
				/*this decrements the tens digit when the ones digit reaches 0*/
				if(0 == *seconds_tens){
					*seconds_tens = 5;
					}else{
					(*seconds_tens)--;
				}
				/*update the tens digit*/
				LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc - 1);
				LCD_Write_Number(*seconds_tens);
				}else{
				(*seconds_ones)--;
			}
			LCD_Write_Number(*seconds_ones);
			/*to keep the cursor from modifying other digits*/
			LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
			break;
			/********************default*********************/
			default:
			break;
		}
		five_sec_timeout = 0;
		}else{
		/*do nothing*/;
	}
	/************************************************************************/
	/*if the move right button is pressed...*/
	BTN_pressed(DIO_PORTD, DIO_PIN7, &move_right);
	if(move_right){
		/*modify cursor location*/
		cursor_loc--;
		if(COLON_LOC == cursor_loc){
			cursor_loc = MINUTES_ONES_LOC;
			/*to get back to the  start location*/
			} else if((MINUTES_TENS_LOC - 1) == cursor_loc){
			cursor_loc = SECONDS_ONES_LOC;
			} else{
			/*do nothing*/;
		}
		/*move the cursor*/
		LCD_LINE_position(MODIFY_ALARM_LINE, cursor_loc);
		five_sec_timeout = 0;
		}else{
		/*do nothing*/;
	}
	return state_error;
}

/*
*	Inputs: None
*	Outputs: either success or fail.
*	Description: Initializes required drivers.
*/
ERROR_STATE alarm_scheduler_init(){
	ERROR_STATE state_error = SUCCESS;
	/*Buttons*/
	BTN_Initialization(DIO_PORTD, DIO_PIN3);
	BTN_Initialization(DIO_PORTD, DIO_PIN5);
	BTN_Initialization(DIO_PORTD, DIO_PIN6);
	BTN_Initialization(DIO_PORTD, DIO_PIN7);
	/*LCD*/
	LCD_Initialize();
	/*Timers*/
	Timer1_Initialize();
	return state_error;
}

/*
*	Inputs: minutes, seconds, and the location to print the alarm.
*	Outputs: either success or fail.
*	Description: Prints the alarm on the LCD and returns the cursor to its original location.
*	The alarm is printed in the following format 'MM:SS'
*/
ERROR_STATE printAlarm(UINT8_t minutes, UINT8_t seconds,LCD_LINES Line_Pos, UINT8_t cursor_loc){
	ERROR_STATE state_error = SUCCESS;
	/*modify cursor position*/
	LCD_LINE_position(Line_Pos, cursor_loc);
	/*print the alarm*/
	LCD_Write_Number(minutes / 10);
	LCD_Write_Number(minutes % 10);
	LCD_Write_Character(':');
	LCD_Write_Number(seconds / 10);
	LCD_Write_Number(seconds % 10);
	/*return to th original location*/
	LCD_LINE_position(Line_Pos, cursor_loc);
	
	return state_error;
}

/*
*	Inputs: None
*	Outputs: either success or fail.
*	Description: main function that handles switching between setting new alarms and modifying
*	set alarms. This function is called in the main.
*/
ERROR_STATE alarm_scheduler(){
	/*local initializations*/
	ERROR_STATE state_error = SUCCESS;
	/*buttons*/
	bool button_1_val = FALSE;
	bool button_2_val = FALSE;
	bool button_3_val = FALSE;
	bool button_4_val = FALSE;
	/*cursor*/
	UINT8_t cursor_loc = 1;
	/*alarm values*/
	UINT8_t minutes_tens = 0;
	UINT8_t minutes_ones = 0;
	UINT8_t seconds_tens = 0;
	UINT8_t seconds_ones = 0;
	/**********************************Operations page**************************************/
	/*print available operations*/
	LCD_Clear();
	LCD_LINE_position(LCD_LINE1, 1);
	LCD_Write_String("1) New Alarm");
	LCD_LINE_position(LCD_LINE2, 1);
	LCD_Write_String("2) Modify Alarm");
	/*print buttons action*/
	Display_Action_Buttons(Three_Buttons);
	/*wait for a user response*/
	while(!button_1_val && !button_2_val && !button_3_val){
		BTN_pressed(DIO_PORTD, DIO_PIN7, &button_1_val);
		BTN_pressed(DIO_PORTD, DIO_PIN6, &button_2_val);
		BTN_pressed(DIO_PORTD, DIO_PIN5, &button_3_val);
	}
	/**********************************Set new alarm page**************************************/
	if(button_1_val){
		/*to limit available alarms to only 3*/
		if(3 > usr_def_alarms){
			LCD_Clear();
			LCD_Write_String("*Setting new alarm*");
			/*print buttons action*/
			LCD_LINE_position(LCD_LINE4, 5);
			LCD_Write_Character(0x7F);
			LCD_LINE_position(LCD_LINE4, 8);
			LCD_Write_Character(0x2D);
			LCD_LINE_position(LCD_LINE4, 11);
			LCD_Write_Character(0x2B);
			LCD_LINE_position(LCD_LINE4, 14);
			LCD_Write_Character(0x7E);
			/*print default alarm*/
			printAlarm(0, 0,LCD_LINE2, 8);
			five_sec_timeout = 0;
			/*wait for user to set alarm*/
			while(5 > five_sec_timeout){
				/*if user is idle for 5 seconds, th alarm values will be saved*/
				modifyAlarm(&minutes_tens, &minutes_ones, &seconds_tens, &seconds_ones);
			}
			UINT8_t min=(minutes_tens * (UINT8_t)10) + minutes_ones;
			UINT8_t sec =(seconds_tens * (UINT8_t)10) + seconds_ones;
			/*store alarm values*/
			if((min!= 0) || (sec != 0)){
				alarm_ptr_arr[usr_def_alarms].minutes = min;
				alarm_ptr_arr[usr_def_alarms].seconds = sec;
				alarm_ptr_arr[usr_def_alarms].Fire_Time=(((UINT16_t)min*60)+(UINT16_t)sec)+Current_Time;
				++usr_def_alarms;
			}

			}else{
			/*in case all 3 alarms are used*/
			LCD_Clear();
			LCD_LINE_position(LCD_LINE2, 8);
			LCD_Write_String("No free alarms left!");
		}
		/**********************************modify alarm page**************************************/
		} else if (button_2_val){
		if(usr_def_alarms != 0){
			cursor_loc = 1;
			LCD_Clear();
			LCD_LINE_position(LCD_LINE1, 2);
			LCD_Write_String("**Choose Alarm**");
			LCD_LINE_position(LCD_LINE2, cursor_loc);
			/*print all alarms set by the user*/
			for(UINT8_t alarm_index = 0; usr_def_alarms > alarm_index; ++alarm_index){
				printAlarm(alarm_ptr_arr[alarm_index].minutes, alarm_ptr_arr[alarm_index].seconds,LCD_LINE2, cursor_loc);
				cursor_loc+=7;
			}
			/*print buttons action*/
			Display_Action_Buttons(All_Buttons);
			/*reset button status*/
			button_1_val = FALSE;
			button_2_val = FALSE;
			button_3_val = FALSE;
			/*wait for a user response*/
			Check_Button_Update(&button_1_val, &button_2_val, &button_3_val, &button_4_val);
			if(button_1_val){
				modify_set_alarm(Alarm_1, &minutes_tens, &minutes_ones, &seconds_tens, &seconds_ones);
				/*in case alarm 2 is chosen*/
				} else if(button_2_val){
				modify_set_alarm(Alarm_2, &minutes_tens, &minutes_ones, &seconds_tens, &seconds_ones);
				/*in case alarm 3 is chosen*/
				} else if(button_3_val){
				modify_set_alarm(Alarm_3, &minutes_tens, &minutes_ones, &seconds_tens, &seconds_ones);
				/*to exit the modify alarm page*/
				} else if(button_4_val){
				/*do nothing*/;
				} else{
				/*do nothing*/;
			}
			}else{
			LCD_Clear();
			LCD_Write_String("No Alarms Set");
			_delay_ms(2000);
		}

		/*to exit the operations page*/
		} else if(button_3_val){
		/*do nothing*/;
		} else{
		/*do nothing*/;
	}
	return state_error;
}

/*
*	Inputs: addresses to boolean variables in which the button status will be stored.
*	Outputs: None
*	Description: stores sets the variable when the relative button is pressed.
*/
void Check_Button_Update(bool* button_1_val,bool* button_2_val,bool* button_3_val,bool* button_4_val){
	while(!(*button_1_val) && !(*button_2_val) && !(*button_3_val) && !(*button_4_val)){
		if(usr_def_alarms > 0){
			BTN_pressed(DIO_PORTD, DIO_PIN7, button_1_val);
			}else{
			/*do nothing*/;
		}
		if(usr_def_alarms > 1){
			BTN_pressed(DIO_PORTD, DIO_PIN6, button_2_val);
			}else{
			/*do nothing*/;
		}
		if(usr_def_alarms > 2){
			BTN_pressed(DIO_PORTD, DIO_PIN5, button_3_val);
			}else{
			/*do nothing*/;
		}
		BTN_pressed(DIO_PORTD, DIO_PIN3, button_4_val);
	}
}

/*
*	Inputs: number of buttons to be displayed
*	Outputs: None
*	Description: Displays the action buttons at the bottom of the screen.
*/
void Display_Action_Buttons(Buttons_Display Num_Of_Buttons){
	LCD_LINE_position(LCD_LINE4, 5);
	LCD_Write_Character('1');
	LCD_LINE_position(LCD_LINE4, 8);
	LCD_Write_Character('2');
	LCD_LINE_position(LCD_LINE4, 11);
	if(Num_Of_Buttons == Three_Buttons){
		LCD_Write_Character('X');
		}else{
		if(Num_Of_Buttons == Three_Buttons_No_X){
			LCD_Write_Character('3');
			LCD_LINE_position(LCD_LINE4,14);
			LCD_Write_Character('|');
			}else{
			LCD_Write_Character('3');
			LCD_LINE_position(LCD_LINE4, 14);
			LCD_Write_Character('X');
		}
	}
}

/*
*	Inputs: alarm number and addresses of tens and ones units of both minutes and seconds.
*	Outputs: None
*	Description: Modifies the alarm provided set by the user.
*/
void modify_set_alarm(alarms alarm_num, UINT8_t* minutes_tens, UINT8_t* minutes_ones, UINT8_t* seconds_tens, UINT8_t* seconds_ones){
	LCD_Clear();
	LCD_Write_String(" **Modify alarm ");
	LCD_Write_Number(alarm_num + 1);
	LCD_Write_String("**");
	/*print buttons action*/
	LCD_LINE_position(LCD_LINE4, 5);
	LCD_Write_Character(0x7F);
	LCD_LINE_position(LCD_LINE4, 8);
	LCD_Write_Character(0x2D);
	LCD_LINE_position(LCD_LINE4, 11);
	LCD_Write_Character(0x2B);
	LCD_LINE_position(LCD_LINE4, 14);
	LCD_Write_Character(0x7E);
	/*print old alarm values*/
	printAlarm(alarm_ptr_arr[alarm_num].minutes, alarm_ptr_arr[alarm_num].seconds,LCD_LINE2, 8);
	/*retrieve old alarm values*/
	*minutes_tens = (alarm_ptr_arr[alarm_num].minutes) / 10;
	*minutes_ones = (alarm_ptr_arr[alarm_num].minutes) % 10;
	*seconds_tens = (alarm_ptr_arr[alarm_num].seconds) / 10;
	*seconds_ones = (alarm_ptr_arr[alarm_num].seconds) % 10;
	/*wait for user to set alarm*/
	five_sec_timeout = 0;
	while(5 > five_sec_timeout){
		modifyAlarm(minutes_tens, minutes_ones, seconds_tens, seconds_ones);
	}
	UINT8_t min=(*minutes_tens * (UINT8_t)10) + *minutes_ones;
	UINT8_t sec =(*seconds_tens * (UINT8_t)10) + *seconds_ones;
	/*store alarm values*/
	if((min!= 0) || (sec != 0)){
		alarm_ptr_arr[alarm_num].minutes = min;
		alarm_ptr_arr[alarm_num].seconds = sec;
		alarm_ptr_arr[alarm_num].Fire_Time=(((UINT16_t)min*60)+(UINT16_t)sec)+Current_Time;
	}

}
