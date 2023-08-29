/*
 * TIMER_1_Interface.c
 *
 * Created: 8/27/2023 2:00:06 PM
 *  Author: aliae
 */ 
#include "TIMER_1_Private.h"

void Timer1_Initialize(){
	Set_Global_Initialize(ON);
	TCCR1A = 0x00;
	TCCR1B = 0x0D;
	OCR1A = 15625;
	SET_BIT(TIMSK,OCIE1A);
	SET_BIT(TIFR,OCF1A);
}