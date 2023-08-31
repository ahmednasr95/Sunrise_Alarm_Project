

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
 
#include "CPU_Configuration.h"

#define TIMER0_CNTR_REG		TCCR0
#define	INTTERUPT_FLAG_REG	TIMSK

#define TIMER0_OVF			VECTOR(11)
#define TIMER0_COMP			VECTOR(10)

void Timer0_Initialize();
void Timer0_STOP();
void Timer0_ON();
void SET_DUTY_CYCLE(UINT8_t duty_cycle);

#endif /* TIMER0_PRIVATE_H_ */