#include "Potentiometer_Private.h"

ERROR_STATE LDR_init(){
	ERROR_STATE state_error = SUCCESS;
	if(ADC_Initialize()){
		state_error = SUCCESS;
	}else{
		state_error = FAIL;
	}
	return state_error;
}

ERROR_STATE LDR_Read(UINT16_t* POT_value){
	ERROR_STATE state_error = SUCCESS;
	if(ADC_Read(LDR_PIN,POT_value)){
		state_error = SUCCESS;
	}else{
		state_error = FAIL;
	}
	return state_error;
}
