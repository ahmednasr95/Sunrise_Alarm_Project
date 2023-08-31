
#include "BLUE_LED_Private.h"

ERROR_STATE BLUE_LED_Initializ(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Direction(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_OUTPUT);
	return state_error;
}
ERROR_STATE BLUE_LED_ON(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_HIGH);
	return state_error;
}
ERROR_STATE BLUE_LED_OFF(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_LOW);
	return state_error;
}
ERROR_STATE BLUE_LED_TGL(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_TglPin_Value(BLUE_LED_PORT,BLUE_LED_PIN);
	return state_error;
}
/**/