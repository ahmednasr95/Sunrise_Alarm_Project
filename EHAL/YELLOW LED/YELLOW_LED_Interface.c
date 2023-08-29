/*
 * YELLOW_LED_Interface.c
 *
 * Created: 8/20/2023 10:18:28 AM
 *  Author: aliae
 */ 
#include "YELLOW_LED_Private.h"

void YELLOW_LED_Initializ(void){
	DIO_SetPin_Direction(YELLOW_LED_PORT,YELLOW_LED_PIN,YELLOW_LED_OUTPUT);
}
void YELLOW_LED_ON(void){
	DIO_SetPin_Value(YELLOW_LED_PORT,YELLOW_LED_PIN,YELLOW_LED_HIGH);
}
void YELLOW_LED_OFF(void){
	DIO_SetPin_Value(YELLOW_LED_PORT,YELLOW_LED_PIN,YELLOW_LED_LOW);
}
void YELLOW_LED_TGL(void){
	DIO_TglPin_Value(YELLOW_LED_PORT,YELLOW_LED_PIN);
}