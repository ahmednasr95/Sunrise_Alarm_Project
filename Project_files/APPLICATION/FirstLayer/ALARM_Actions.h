
#ifndef ALARM_Actions_H_
#define ALARM_Actions_H_

#include "ALL_LEDS.h"
#include "Buzzer_Private.h"
#include "Potentiometer_Private.h"

#include "ALARM_Arrange.h"


void Alarm_Action(void);
void Nearest_Time_Display(void);
void Timing_Calculate(void);

void swap(alarm_struct *a, alarm_struct *b) ;

void customSort(alarm_struct arr[], UINT16_t n);

#endif /* ALARM_Actions_H_ */