/*
 * RED_LED_Private.h
 *
 * Created: 8/18/2023 12:17:49 PM
 *  Author: aliae
 */ 


#ifndef RED_LED_PRIVATE_H_
#define RED_LED_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define RED_LED_PIN		DIO_PIN7
#define RED_LED_PORT	DIO_PORTB

#define RED_LED_OUTPUT	DIO_OUTPUT

#define RED_LED_HIGH	DIO_HIGH
#define RED_LED_LOW		DIO_LOW

// Function Prototype:
void RED_LED_Initializ(void);
void RED_LED_ON(void);
void RED_LED_OFF(void);
void RED_LED_TGL(void);

#endif /* RED_LED_PRIVATE_H_ */