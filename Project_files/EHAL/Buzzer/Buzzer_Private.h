
#ifndef BUZZER_PRIVATE_H_
#define BUZZER_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define BUZZER_PIN		DIO_PIN6
#define BUZZER_PORT		DIO_PORTC

#define BUZZER_OUTPUT		DIO_OUTPUT

#define BUZZER_HIGH		DIO_HIGH
#define BUZZER_LOW		DIO_LOW

// Function Prototype:
ERROR_STATE BUZZER_Initialize(void);
ERROR_STATE BUZZER_ON(void);
ERROR_STATE BUZZER_OFF(void);
ERROR_STATE BUZZER_TGL(void);

#endif /* BUZZER_PRIVATE_H_ */