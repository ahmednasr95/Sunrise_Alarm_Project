

#ifndef AHMED_NASR_H_
#define AHMED_NASR_H_

/*required drivers*/
#include "LCD_Private.h"
#include "button_Private.h"
#include "TIMER_1_Private.h"

/*definitions*/
#define NUM_OF_ALARMS 3

#define MODIFY_ALARM_CURSOR_LOC		8
#define MODIFY_ALARM_LINE			LCD_LINE2

#define MINUTES_TENS_LOC	MODIFY_ALARM_CURSOR_LOC
#define MINUTES_ONES_LOC	MODIFY_ALARM_CURSOR_LOC + 1
#define COLON_LOC			MODIFY_ALARM_CURSOR_LOC + 2
#define SECONDS_TENS_LOC	MODIFY_ALARM_CURSOR_LOC + 3
#define SECONDS_ONES_LOC	MODIFY_ALARM_CURSOR_LOC + 4

/*global variables*/
typedef struct{
	UINT8_t minutes;
	UINT8_t seconds;
	UINT16_t Fire_Time;
}alarm_struct;

typedef enum {
	Alarm_1,
	Alarm_2,
	Alarm_3
}alarms;

typedef enum{
	Three_Buttons_No_X = 2,
	Three_Buttons = 3,
	All_Buttons = 4
}Buttons_Display;

/*function prototypes*/

void Check_Button_Update(bool* button_1_val,bool* button_2_val,bool* button_3_val,bool* button_4_val);

void Display_Action_Buttons(Buttons_Display Num_Of_Buttons);

void modify_set_alarm(alarms alarm_num, UINT8_t* minutes_tens, UINT8_t* minutes_ones, UINT8_t* seconds_tens, UINT8_t* seconds_ones);

ERROR_STATE modifyAlarm(UINT8_t* minutes_tens, UINT8_t* minutes_ones, UINT8_t* seconds_tens, UINT8_t* seconds_ones);

ERROR_STATE alarm_scheduler_init(void);

ERROR_STATE printAlarm(UINT8_t minutes, UINT8_t seconds,LCD_LINES Line_Pos, UINT8_t cursor_loc);

ERROR_STATE alarm_scheduler(void);

#endif /* AHMED_NASR_H_ */