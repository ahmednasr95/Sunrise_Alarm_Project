
#include "LCD_Private.h"

ERROR_STATE LCD_Initialize(void)
{
	ERROR_STATE state_error = SUCCESS;
	//Define direction for pins
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D4, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D5, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D6, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D7, LCD_OUT);
	
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_RS, LCD_OUT);
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_EN, LCD_OUT);
	_delay_ms(20);
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x0F);
	_delay_ms(10);
	return state_error;
}
ERROR_STATE LCD_Clear(void)
{
	ERROR_STATE state_error = SUCCESS;
	LCD_Write_Command(0x01);
	return state_error;
}

ERROR_STATE LCD_Write_Command(UINT8_t command)
{
	ERROR_STATE state_error = SUCCESS;
	//Send high nibble first
	//LCD = (LCD & 0x0F) | (command & 0xF0);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(command,7));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(command,6));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(command,5));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(command,4));
	//Register select will select control register
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_LOW);
	//Write on LCD
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_us(200);
	//Send low nibble
	//LCD =  (LCD & 0x0F) | (command << 4);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(command,3));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(command,2));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(command,1));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(command,0));
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
	return state_error;
}

ERROR_STATE LCD_Write_Character(UINT8_t character)
{
	ERROR_STATE state_error = SUCCESS;
	//Send high nibble first
	//LCD = (LCD & 0x0F) | (character & 0xF0);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(character,7));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(character,6));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(character,5));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(character,4));
	//Register select will select data register
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_HIGH);
	//Write on LCD
	
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_us(200);
	//Send lower nibble
	//LCD =  (LCD & 0x0F) | (character << 4);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(character,3));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(character,2));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(character,1));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(character,0));
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
	return state_error;
}

ERROR_STATE LCD_Write_String(const char *str)
{
	ERROR_STATE state_error = SUCCESS;
	while (*str != '\0')
	{
		LCD_Write_Character(*str);
		str++;
	}
	return state_error;
}

ERROR_STATE LCD_Write_Number(SINT64_t number)
{
	ERROR_STATE state_error = SUCCESS;
	if(number < 0){
		LCD_Write_Character('-');
		number*=(-1);
	}
	SINT64_t num = number;
	UINT16_t digit = 0;
	while(num != 0){
		digit++;
		num/=10;
	}
	if(number == 0){
		LCD_Write_Character('0');
		}else{
		UINT8_t arr_num[20];
		
		for(int i = digit-1 ; i >= 0 ;i--){
			arr_num[i]=number %10 + '0';
			number/=10;
		}
		//itoa(number , arr_num , 10);
		for(int i =0 ; i<digit;i++){
			LCD_Write_Character(arr_num[i]);
		}
	}
	return state_error;
}

ERROR_STATE LCD_Write_FloatNumber(fint64_t Fnumber)
{
	ERROR_STATE state_error = SUCCESS;
	if(Fnumber<0){
		LCD_Write_Character('-');
		Fnumber*=(-1);
	}
	SINT64_t intfnumber = (SINT64_t)Fnumber;
	LCD_Write_Number(intfnumber);

	SINT64_t decimalp = ((Fnumber - (fint64_t)intfnumber) * pow(10, DICIMAL_POINT_ACCURACY));
	SINT64_t num = decimalp;
	UINT16_t digit = 0,ref_numb =DICIMAL_POINT_ACCURACY , ref_flag=0;
	while(num != 0){
		if(num%10 == 0 && !ref_flag){
			ref_numb--;
			decimalp/=10;
			}else{
			ref_flag =1;
			digit++;
		}
		
		num/=10;
	}
	if(decimalp != 0){
		LCD_Write_Character('.');
		while(digit<ref_numb){
			LCD_Write_Character('0');
			digit++;
		}
		LCD_Write_Number(decimalp);
	}
	return state_error;
}

/*
Inputs:	row and column
Output:	state
Description: Moves the cursor position to the provided
row and column.
*/
ERROR_STATE LCD_LINE_position(LCD_LINES row , SINT8_t column){
	ERROR_STATE state_error = SUCCESS;
	UINT8_t address = 0;
	
	if(column < 20 && column >= 0){
		switch(row){
			case LCD_LINE1:
			address = 0x00;
			break;
			case LCD_LINE2:
			address = 0x40;
			break;
			case LCD_LINE3:
			address = 0x14;
			break;
			case LCD_LINE4:
			address = 0x54;
			break;
			default:
			state_error = FAIL;
			break;
		}
		if(SUCCESS == state_error){
			address += column;
			LCD_Write_Command(0x80+address);
			}else{
			;
		}
		}else{
		state_error = FAIL;
	}

	return state_error;
}