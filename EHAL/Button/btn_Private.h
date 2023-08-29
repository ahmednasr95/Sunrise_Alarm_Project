
#ifndef BTN_1_PRIVATE_H_
#define BTN_1_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define BTN_INPUT		DIO_INPUT

typedef enum{
	BTN_1=DIO_PORTD,
	BTN_2=DIO_PORTD,
	BTN_3=DIO_PORTD,
	BTN_4=DIO_PORTD,
	}BTN_NUM;
typedef enum{
	BTN_1_PIN=DIO_PIN7,
	BTN_2_PIN=DIO_PIN6,
	BTN_3_PIN=DIO_PIN5,
	BTN_4_PIN=DIO_PIN3
	}BTN_PIN;

// Function Prototype:
ERROR_STATE BTN_Initialization(BTN_NUM port, BTN_PIN pin);
ERROR_STATE BTN_pressed(BTN_NUM port, BTN_PIN pin,bool* btn_state);

#endif /* BTN_1_PRIVATE_H_ */