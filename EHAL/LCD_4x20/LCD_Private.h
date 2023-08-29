
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define LCD_DATA_PORT  DIO_PORTB
#define LCD_CNTRL_PORT DIO_PORTA

#define LCD_RS DIO_PIN3
#define LCD_EN DIO_PIN2


#define LCD_D4 DIO_PIN0
#define LCD_D5 DIO_PIN1
#define LCD_D6 DIO_PIN2
#define LCD_D7 DIO_PIN4

#define LCD_OUT  DIO_OUTPUT
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH

typedef enum{
	LCD_LINE1,
	LCD_LINE2,
	LCD_LINE3,
	LCD_LINE4
}LCD_LINES;

#define DICIMAL_POINT_ACCURACY 8

// Function Prototype:
ERROR_STATE LCD_Initialize(void);
ERROR_STATE LCD_Curser_OFF(void);
ERROR_STATE LCD_Curser_ON(void);
ERROR_STATE LCD_Clear(void);
ERROR_STATE LCD_Write_Command(UINT8_t command);
ERROR_STATE LCD_Write_Character(UINT8_t character);
ERROR_STATE LCD_Write_String(const char *str);
ERROR_STATE LCD_Write_Number(SINT64_t number);
ERROR_STATE LCD_Write_FloatNumber(fint64_t Fnumber);
ERROR_STATE LCD_Write_SpecialCharacter(UINT8_t Scharcter);
ERROR_STATE LCD_LINE_position(LCD_LINES row , SINT8_t column);

#endif /* LCD_PRIVATE_H_ */