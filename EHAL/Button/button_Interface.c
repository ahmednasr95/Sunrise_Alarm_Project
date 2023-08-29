
#include "button_Private.h"

bool BTN_OneTime = LOW;
ERROR_STATE BTN_Initialization(DIO_Port port, DIO_Pin pin){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Direction(port , pin , DIO_INPUT);
	return state_error;
}
ERROR_STATE BTN_pressed(DIO_Port port, DIO_Pin pin, bool* btn_state){
	ERROR_STATE state_error = SUCCESS;
	bool Btn_clicked;
	bool return_value = LOW;
	DIO_GetPin_Value(port, pin, &Btn_clicked);
	while((Btn_clicked) == LOW){
		return_value =HIGH;
		DIO_GetPin_Value(port, pin, &Btn_clicked);
	}
	//return_value =LOW;
	_delay_ms(30);
	while((Btn_clicked) == LOW){
		return_value =HIGH;
		DIO_GetPin_Value(port, pin, &Btn_clicked);
	}
	*btn_state = return_value;
	return state_error;
}