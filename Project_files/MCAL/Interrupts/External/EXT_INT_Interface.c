

#include "EXT_INT_Private.h"


ERROR_STATE Set_Global_Initialize(GLB_MODE mode){
	ERROR_STATE state_error = SUCCESS;
	SREG |= mode;
	if(mode == ON){
		if(!GET_BIT(SREG,7)){
			state_error = FAIL;
		}else{
			state_error = SUCCESS;
		}
	}else{
		if(mode == OFF){
			if(GET_BIT(SREG,7)){
				state_error = FAIL;
			}else{
				state_error = SUCCESS;
			}
		}else{
			state_error = FAIL;
		}
	}
	return state_error;
}
ERROR_STATE INT_0_Initialize(INT interrupt,INT_mode interrupt_mode){
	ERROR_STATE state_error = SUCCESS;
	if(DIO_SetPin_Direction(DIO_PORTD,DIO_PIN2,DIO_INPUT)){
		if(Set_Global_Initialize(ON)){
			INT_REG_CNTR |= interrupt_mode;
			INT_EN_REQ_PORT |= interrupt;
		}else{
			state_error =FAIL;
		}
	}else{
		state_error =FAIL;
	}
	return state_error;
}
ERROR_STATE INT_1_Initialize(INT_1 interrupt,INT_1_mode interrupt_mode){
	ERROR_STATE state_error = SUCCESS;
	if(DIO_SetPin_Direction(DIO_PORTD,DIO_PIN3,DIO_INPUT)){
		if(Set_Global_Initialize(ON)){
			INT_REG_CNTR |= interrupt_mode;
			INT_EN_REQ_PORT |= interrupt;
			}else{
			state_error =FAIL;
		}

		}else{
		state_error =FAIL;
	}
	return state_error;
}
ERROR_STATE INT_2_Initialize(INT_2 interrupt_2,INT_2_mode interrupt_2_mode){

	ERROR_STATE state_error = SUCCESS;
	if(DIO_SetPin_Direction(DIO_PORTB,DIO_PIN2,DIO_INPUT)){
		if(Set_Global_Initialize(ON)){
			INT_REG_CNTR |= interrupt_2_mode;
			INT_EN_REQ_PORT |= interrupt_2;
			}else{
			state_error =FAIL;
		}
	}else{
		state_error =FAIL;
	}

	return state_error;
}