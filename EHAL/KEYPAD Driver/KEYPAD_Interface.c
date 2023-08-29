#include "KEYPAD_Private.h"

const volatile UINT8_t keypad[4][4] =
{
	{'1', '2','3', '4'},

	{'5', '6', '7','8'},

	{'9', '0', 'n', 'n'},

	{'n', 'n', 'n', 'n'}
};

ERROR_STATE KEYPAD_Initialize(void)
{
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT1, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT2, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT3, KEYPAD_OUT);

	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT1, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT2, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT3, KEYPAD_HIGH);

	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP0, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP1, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP2, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP3, KEYPAD_INP);

return SUCCESS;

}

ERROR_STATE KEYPAD_Read(UINT8_t* keypad_char)
{
	UINT8_t btn = 'n',keypad_value;
	UINT8_t Row_Loc ;
	UINT8_t Col_Loc ;
	for (Row_Loc = KEYPAD_ROW_END; Row_Loc >= KEYPAD_ROW_STRT; Row_Loc--)
	{
			DIO_SetPin_Value(KEYPAD_PORT_OUT, Row_Loc, KEYPAD_LOW);
			for (Col_Loc = KEYPAD_COL_STRT; Col_Loc >= KEYPAD_COL_END; Col_Loc--)
			{
				if(Col_Loc == 4){
					DIO_GetPin_Value(KEYPAD_PORT_INP, 3,&keypad_value);
						while( keypad_value== KEYPAD_PRESSED)
						{
							DIO_GetPin_Value(KEYPAD_PORT_INP, 3,&keypad_value);
							btn = keypad[KEYPAD_ROW_END - Row_Loc][3];
						}
						_delay_ms(10);
					
				}else{
					DIO_GetPin_Value(KEYPAD_PORT_INP, Col_Loc,&keypad_value);
						while (keypad_value == KEYPAD_PRESSED)
						{
							DIO_GetPin_Value(KEYPAD_PORT_INP, Col_Loc,&keypad_value);
							btn = keypad[KEYPAD_ROW_END - Row_Loc][ KEYPAD_COL_STRT - Col_Loc ];
						}
						_delay_ms(10);
					
				}
			}
			DIO_SetPin_Value(KEYPAD_PORT_OUT, Row_Loc, KEYPAD_HIGH);
	}
	*keypad_char = btn;
	return SUCCESS;
}
