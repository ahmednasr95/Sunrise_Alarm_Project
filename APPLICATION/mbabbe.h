
#ifndef MBABBE_H_
#define MBABBE_H_

#include "ALL_LEDS.h"
#include "Buzzer_Private.h"
#include "Potentiometer_Private.h"
#include "Seif.h"

ERROR_STATE Sort_Alarms(void);

void Alarm_Action(void);
void Nearest_Time_Display(void);
void Timing_Calculate(void);

void swap(alarm_struct *a, alarm_struct *b) ;

void bubbleSort(alarm_struct arr[], UINT16_t n);

#endif /* MBABBE_H_ */