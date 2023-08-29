
#include "TIMER0_Private.h"


void Timer0_Initialize(){
Set_Global_Initialize(ON);
/*PHASE_CORRECT pwm*/
TIMER0_CNTR_REG = 0x43;
/*COMP interrupt*/
INTTERUPT_FLAG_REG |= 0x03;
/*TIMTTERUPT FLAG*/
SET_BIT(TIFR,OCF0);
}

void SET_DUTY_CYCLE(UINT8_t duty_cycle){
	if(duty_cycle>99){
		duty_cycle=99;
	}
	if(duty_cycle<1){
		duty_cycle=1;
	}
	OCR0 = ((duty_cycle*255)/100);
}

void Timer0_STOP(){
	//TCCR0 &= ~0x03;
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}
void Timer0_ON(){
	//TCCR0 |= 0x03;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}