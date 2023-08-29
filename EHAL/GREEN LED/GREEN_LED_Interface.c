/*
 * GREEN_LED_Interface.c
 *
 * Created: 8/20/2023 10:18:36 AM
 *  Author: aliae
 */ 
#include "GREEN_LED_Private.h"

void GREEN_LED_Initializ(void){
	DIO_SetPin_Direction(GREEN_LED_PORT,GREEN_LED_PIN,GREEN_LED_OUTPUT);
}
void GREEN_LED_ON(void){
	DIO_SetPin_Value(GREEN_LED_PORT,GREEN_LED_PIN,GREEN_LED_HIGH);
}
void GREEN_LED_OFF(void){
	DIO_SetPin_Value(GREEN_LED_PORT,GREEN_LED_PIN,GREEN_LED_LOW);
}
void GREEN_LED_TGL(void){
	DIO_TglPin_Value(GREEN_LED_PORT,GREEN_LED_PIN);
}