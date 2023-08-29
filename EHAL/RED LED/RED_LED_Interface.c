/*
 * RED_LED_Interface.c
 *
 * Created: 8/18/2023 12:21:33 PM
 *  Author: aliae
 */ 

#include "RED_LED_Private.h"

void RED_LED_Initializ(void){
	DIO_SetPin_Direction(RED_LED_PORT,RED_LED_PIN,RED_LED_OUTPUT);
}
void RED_LED_ON(void){
	DIO_SetPin_Value(RED_LED_PORT,RED_LED_PIN,RED_LED_HIGH);
}
void RED_LED_OFF(void){
	DIO_SetPin_Value(RED_LED_PORT,RED_LED_PIN,RED_LED_LOW);
}
void RED_LED_TGL(void){
	DIO_TglPin_Value(RED_LED_PORT,RED_LED_PIN);
}