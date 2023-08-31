
#include "ADC_Private.h"

ERROR_STATE ADC_Initialize(){
	CLR_BIT(ADC_REF_voltage,REF_BIT1);SET_BIT(ADC_REF_voltage,REF_BIT0);
	SET_BIT(ADC_CNTR_State,ADC_EN_BIT);
	SET_BIT(ADC_CNTR_State,ADC_PRESCALER_BIT2);SET_BIT(ADC_CNTR_State,ADC_PRESCALER_BIT1);SET_BIT(ADC_CNTR_State,ADC_PRESCALER_BIT0);
	return SUCCESS;
}

ERROR_STATE ADC_Read(ADC_PIN channel,UINT16_t* adc_value){
	ADC_REF_voltage &= 0xf0;
	ADC_REF_voltage |= channel;
	CLR_BIT(ADC_CNTR_State,ADC_INTERRUPT_EN);
	CLR_BIT(ADC_CNTR_State,ADC_AUTO_TRIGGER_EN);
	SET_BIT(ADC_CNTR_State,ADC_START_CONVERSION);
	while(GET_BIT(ADC_CNTR_State,ADC_NORMAL_FLAG));
	*adc_value = ADCL;
	return SUCCESS;
}
ERROR_STATE ADC_INT_Read(ADC_PIN channel){
	ERROR_STATE state_error = SUCCESS;
	ADC_REF_voltage &= 0xF0;
	ADC_REF_voltage |= channel;
	SET_BIT(ADC_CNTR_State,ADC_AUTO_TRIGGER_EN);
	ADC_SPECIAL_REG &= 0x0F;
	ADC_SPECIAL_REG |= 0x00;
	if(Set_Global_Initialize(ON)){
			SET_BIT(ADC_CNTR_State,ADC_INTERRUPT_EN);
			SET_BIT(ADC_CNTR_State,ADC_START_CONVERSION);
	}else{
		state_error = FAIL;
	}

	return state_error;
}