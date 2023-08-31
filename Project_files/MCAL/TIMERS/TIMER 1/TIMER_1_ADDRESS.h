/*
 * TIMER_1_ADDRESS.h
 *
 * Created: 8/27/2023 5:35:38 PM
 *  Author: aliae
 */ 


#ifndef TIMER_1_ADDRESS_H_
#define TIMER_1_ADDRESS_H_


#define OCR1A  *((volatile UINT16_t*) 0x4A)
#define TCCR1B  *((volatile UINT8_t*) 0x4E)
#define TCCR1A  *((volatile UINT8_t*) 0x4F)

#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7


#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TICIE1			5
#define OCIE1A			4
#define OCIE1B			3
#define TOIE1			2

#define ICF1			5
#define OCF1A			4
#define OCF1B			3
#define TOV1			2

#endif /* TIMER_1_ADDRESS_H_ */