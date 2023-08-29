/*
 * GREEN_LED_Private.h
 *
 * Created: 8/20/2023 10:15:25 AM
 *  Author: aliae
 */ 


#ifndef GREEN_LED_PRIVATE_H_
#define GREEN_LED_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define GREEN_LED_PIN		DIO_PIN4
#define GREEN_LED_PORT		DIO_PORTA

#define GREEN_LED_OUTPUT	DIO_OUTPUT

#define GREEN_LED_HIGH		DIO_HIGH
#define GREEN_LED_LOW		DIO_LOW

// Function Prototype:
void GREEN_LED_Initializ(void);
void GREEN_LED_ON(void);
void GREEN_LED_OFF(void);
void GREEN_LED_TGL(void);



#endif /* GREEN_LED_PRIVATE_H_ */