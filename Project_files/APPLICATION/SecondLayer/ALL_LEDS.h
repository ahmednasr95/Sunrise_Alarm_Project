
#ifndef ALL_LEDS_H_
#define ALL_LEDS_H_

#include "BLUE_LED_Private.h"
#include "RED_LED_Private.h"
#include "GREEN_LED_Private.h"
#include "YELLOW_LED_Private.h"

#define MAX_DUTY_CYCLE		99
#define MIN_DUTY_CYCLE		1
#define OVF_COUNTER_RESET	0
#define OVF_COUNTER_MAX		2

void ALL_LEDS_Initialize(void);
void ALL_LEDS_TGL(void);
void ALL_LEDS_ON(void);
void ALL_LEDS_OFF(void);
void ALL_LEDS_dimming(void);
void ALL_LEDS_stop_dimming(void);

#endif /* ALL_LEDS_H_ */