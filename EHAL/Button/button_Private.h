
#ifndef BTN_1_PRIVATE_H_
#define BTN_1_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

// Function Prototype:
ERROR_STATE BTN_Initialization(DIO_Port port, DIO_Pin pin);
ERROR_STATE BTN_pressed(DIO_Port port, DIO_Pin pin, bool* btn_state);

#endif /* BTN_1_PRIVATE_H_ */