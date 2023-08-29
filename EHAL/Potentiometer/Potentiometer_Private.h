

#ifndef POTENTIOMETER_PRIVATE_H_
#define POTENTIOMETER_PRIVATE_H_

#include "CPU_Configuration.h"

#define LDR_PIN		ADC_PIN0

ERROR_STATE LDR_init(void);
ERROR_STATE LDR_Read(UINT16_t* POT_value);
#endif /* POTENTIOMETER_PRIVATE_H_ */