
#include "btn_Private.h"

bool BTN_OneTime = LOW;
ERROR_STATE BTN_Initialization(BTN_NUM port, BTN_PIN pin){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Direction(port , pin , BTN_INPUT);
	return state_error;
}
ERROR_STATE BTN_pressed(BTN_NUM port, BTN_PIN pin,bool* btn_state){
	ERROR_STATE state_error = SUCCESS;
	UINT8_t Btn_clicked;
	bool return_value = LOW;
	DIO_GetPin_Value(port,pin,&Btn_clicked);
	if((Btn_clicked) == LOW){
		if(BTN_OneTime == LOW){
			BTN_OneTime = HIGH;
			return_value = HIGH;
		}else{
			return_value =LOW;
		}
	}else{
		BTN_OneTime = LOW;
		return_value = LOW;
	}
	*btn_state = return_value;
	return state_error;
}