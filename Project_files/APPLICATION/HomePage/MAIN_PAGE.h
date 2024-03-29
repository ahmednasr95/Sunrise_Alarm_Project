
#include "ALARM_Actions.h"

#ifndef LCD_TAS_H_
#define LCD_TAS_H_

#define MINUTES_SECONDS_DIGITS	2
#define FIRST					0
#define SECOND					1
#define DELAY_3S				3
#define DELAY_2S				2

ERROR_STATE LCD_Runable_Page(void);
ERROR_STATE LCD_First_Page(void);
ERROR_STATE LCD_Second_Page();

/*ERROR_STATE Set_Alarm(void);*/

#endif /* LCD_TAS_H_ */