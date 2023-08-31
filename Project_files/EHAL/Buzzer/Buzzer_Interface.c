
#include "Buzzer_Private.h"

ERROR_STATE BUZZER_Initialize(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Direction(BUZZER_PORT,BUZZER_PIN,BUZZER_OUTPUT);
	return state_error;
}
ERROR_STATE BUZZER_ON(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BUZZER_PORT,BUZZER_PIN,BUZZER_HIGH);
	return state_error;
}
ERROR_STATE BUZZER_OFF(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BUZZER_PORT,BUZZER_PIN,BUZZER_LOW);
	return state_error;
}
ERROR_STATE BUZZER_TGL(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_TglPin_Value(BUZZER_PORT,BUZZER_PIN);
	return state_error;
}