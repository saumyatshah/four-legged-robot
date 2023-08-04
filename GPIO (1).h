#include <avr/io.h>

#ifndef _GPIO_H
#define _GPIO_H

	#define PA     0
	#define PORTA0 0
	#define PORTA1 1
	#define PORTA2 2
	#define PORTA3 3
	#define PORTA4 4
	#define PORTA5 5
	#define PORTA6 6
	#define PORTA7 7
	
	#define PB     1
	#define PORTB0 10
	#define PORTB1 11
	#define PORTB2 12
	#define PORTB3 13
	#define PORTB4 14
	#define PORTB5 15
	#define PORTB6 16
	#define PORTB7 17

	#define PC     2
	#define PORTC0 20
	#define PORTC1 21
	#define PORTC2 22
	#define PORTC3 23
	#define PORTC4 24
	#define PORTC5 25
	#define PORTC6 26
	#define PORTC7 27

	#define PD     3
	#define PORTD0 30
	#define PORTD1 31
	#define PORTD2 32
	#define PORTD3 33
	#define PORTD4 34
	#define PORTD5 35
	#define PORTD6 36
	#define PORTD7 37
 
		#define PE     4
		#define PORTE0 40
		#define PORTE1 41
		#define PORTE2 42
		#define PORTE3 43
		#define PORTE4 44
		#define PORTE5 45
		#define PORTE6 46
		#define PORTE7 47

		#define PF     5
		#define PORTF0 50
		#define PORTF1 51
		#define PORTF2 52
		#define PORTF3 53
		#define PORTF4 54
		#define PORTF5 55
		#define PORTF6 56
		#define PORTF7 57
	
		#define PG     6
		#define PORTG0 60
		#define PORTG1 61
		#define PORTG2 62
		#define PORTG3 63
		#define PORTG4 64

	#define lowlevel 0
	#define change 1
	#define falling 2
	#define rising 3

	#define ExINT0 0
	#define ExINT1 1
	#define ExINT2 2
	#define ExINT3 3
	#define ExINT4 4
	#define ExINT5 5
	#define ExINT6 6
	#define ExINT7 7

	void configport(uint8_t,uint8_t);
	void set(uint8_t);
	void reset(uint8_t);
	void waitms(unsigned int);
	void waitus(unsigned int);
	void ex_interrupt(uint8_t,uint8_t);

#endif
