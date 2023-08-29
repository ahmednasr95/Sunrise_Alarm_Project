

#ifndef TIMER0_ADDRESS_H_
#define TIMER0_ADDRESS_H_

/* =============================================================
 * 							Timers
 * =============================================================*/


#define OCR0  *((volatile UINT8_t*) 0x5C)
#define TCCR0  *((volatile UINT8_t*) 0x53)
#define FOC0            7
#define WGM00			6
#define COM01			5
#define COM00			4
#define WGM01			3
#define	CS02			2
#define	CS01			1
#define	CS00			0
	    
#define TCNT0 *((volatile UINT8_t*) 0x52)
#define TIMSK *((volatile UINT8_t*) 0x59)

#define OCIE0			1
#define TOIE0			0
	
#define TIFR *((volatile UINT8_t*) 0x58)

#define OCF0			1
#define TOV0            0 




#endif /* TIMER0_ADDRESS_H_ */