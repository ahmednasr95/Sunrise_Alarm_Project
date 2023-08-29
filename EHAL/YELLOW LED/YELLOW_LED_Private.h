/*
 * YELLOW_LED_Private.h
 *
 * Created: 8/20/2023 10:15:13 AM
 *  Author: aliae
 */ 


#ifndef YELLOW_LED_PRIVATE_H_
#define YELLOW_LED_PRIVATE_H_


// Configuration:
#include "CPU_Configuration.h"

#define YELLOW_LED_PIN		DIO_PIN6
#define YELLOW_LED_PORT		DIO_PORTA

#define YELLOW_LED_OUTPUT	DIO_OUTPUT

#define YELLOW_LED_HIGH		DIO_HIGH
#define YELLOW_LED_LOW		DIO_LOW

// Function Prototype:
void YELLOW_LED_Initializ(void);
void YELLOW_LED_ON(void);
void YELLOW_LED_OFF(void);
void YELLOW_LED_TGL(void);


#endif /* YELLOW_LED_PRIVATE_H_ */