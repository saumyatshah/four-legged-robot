#define F_CPU 16000000UL
#include "GPIO.h"
#include <util/delay.h>
#include <avr/interrupt.h>

void configport(uint8_t port , uint8_t stat)
{
	switch(port)
	{
		case PA:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__) || defined (__AVR_ATmega32A__) ||  defined (__AVR_ATmega16A__)
				DDRA = stat;
				PORTA = ~(stat);
			#endif
		break;
		case PB:
		   DDRB = stat;
		   PORTB = ~(stat);
		break;
		case PC:
		   DDRC = stat;
		   PORTC = ~(stat);
		break;
		case PD:
		   DDRD = stat;
		   PORTD = ~(stat);
		break;
		case PE:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
			   DDRE = stat;
			   PORTE = ~(stat);
			#endif
		break;
		case PF:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__) 
				DDRF = stat;
				PORTF = ~(stat);
			#endif
		break;
		case PG:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
				DDRG = stat;
				PORTG = ~(stat);
			#endif
		break;
	}
}

void waitms(unsigned int wait)
{
	
	while (wait>0)
	{
		_delay_ms(1);
		wait--;
	}
}

void waitus(unsigned int wait)
{
	while (wait>0)
	{
		_delay_us(1);
		wait--;
	}
}


void set(uint8_t pin)
{
	uint8_t port = pin/10;
	pin = (pin%10);
	switch(port)
	{
		case PA:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__) || defined (__AVR_ATmega16A__) || defined (__AVR_ATmega32A__)
				PORTA |= (1<<pin);
			#endif
		break;
		case PB:
			PORTB |= (1<<pin);
		break;
		case PC:
			PORTC |= (1<<pin);
		break;
		case PD:
			PORTD |= (1<<pin);
		break;
		case PE:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
				PORTE |= (1<<pin);
			#endif
		break;
		case PF:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
				PORTF |= (1<<pin);
			#endif
		break;
		case PG:
			#if defined (__AVR_ATmega128__ ) || defined (__AVR_ATmega128A__)
				PORTG |= (1<<pin);
			#endif
		break;
	}
}
					   
void reset(uint8_t pin)
{
	uint8_t port = pin/10;
	pin = (pin%10);
	switch(port)
	{
		case PA:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__) || defined (__AVR_ATmega32A__) || defined (__AVR_ATmega16A__)
				PORTA &= ~(1<<pin);
			#endif
		break;
		case PB:
			PORTB &= ~(1<<pin);
		break;
		case PC:
			PORTC &= ~(1<<pin);
		break;
		case PD:
			PORTD &= ~(1<<pin);
		break;
		case PE:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
				PORTE &= ~(1<<pin);
			#endif
		break;
		case PF:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
				PORTF &= ~(1<<pin);
			#endif
		break;
		case PG:
			#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
				PORTG &= ~(1<<pin);
			#endif
		break;
	}
}

void ex_interrupt(uint8_t channel, uint8_t state)
{
	#if defined (__AVR_ATmega8__)
		switch(channel)
		{
			case ExINT0:
				DDRD &= ~(1<<DDD2);
				PORTD |= (1<<PD2);
				GICR |= 1<<INT0;
				MCUCR &= ~(0x03);
				MCUCR |= state;
				break;
			
			case ExINT1:
				DDRD &= ~(1<<DDD3);
				PORTD |= (1<<PD3);
				GICR |= 1<<INT1;
				MCUCR &= ~(3<<2);
				MCUCR |= (state<<2);
				break;
		}
		sei();
	
	#elif defined (__AVR_ATmega16A__) || defined (__AVR_ATmega32__)
		switch(channel)
		{
			case ExINT0:
			DDRD &= ~(1<<DDD2);
			PORTD |= (1<<PD2);
			GICR |= 1<<INT0;
			MCUCR &= ~(0x03);
			MCUCR |= state;
			break;
	
			case ExINT1:
			DDRD &= ~(1<<DDD3);
			PORTD |= (1<<PD3);
			GICR |= 1<<INT1;
			MCUCR &= ~(3<<2);
			MCUCR |= (state<<2);
			break;
		
			case ExINT2:
			DDRB &= ~(1<<DDB2);
			PORTB |= (1<<PB2);
			GICR |= 1<<INT2;
			if (state == rising)
				MCUCSR |= 1<<ISC2;
			else
				MCUCSR &= ~(1<<ISC2);
			break;
		}
		sei();
	
	#elif defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
		switch(channel)
		{
			case ExINT0:
				DDRD &= ~(1<<DDD0);
				PORTD |= (1<<PD0);
				EICRA &= ~(0x03);
				EICRA |= state;
				EIMSK |= 1<<INT0;
			break;
		
			case ExINT1:
				DDRD &= ~(1<<DDD1);
				PORTD |= (1<<PD1);
				EICRA &= ~(3<<2);
				EICRA |= (state<<2);
				EIMSK |= 1<<INT1;
			break;
		
			case ExINT2:
				DDRD &= ~(1<<DDB2);
				PORTD |= (1<<PD2);
				EIMSK |= 1<<INT2;
				EICRA &= ~(3<<4);
				EICRA |= (state<<4);
			break;
        
			case ExINT3:
				DDRD &= ~(1<<DDD3);
				PORTD |= (1<<PD3);
				EICRA &= ~(3<<6);
				EICRA |= (state<<6);
				EIMSK |= 1<<INT3;
			break;
		
			case ExINT4:
				DDRE &= ~(1<<DDE4);
				PORTE |= (1<<PE4);
				EICRB &= ~(0x03);
				EICRB |= (state);
				EIMSK |= 1<<INT4;
			break;
		
			case ExINT5:
				DDRE &= ~(1<<DDE5);
				PORTE |= (1<<PE5);
				EIMSK |= 1<<INT5;
				EICRB &= ~(3<<2);
				EICRB |= (state<<2);
			break;
		
			case ExINT6:
				DDRE &= ~(1<<DDE6);
				PORTE |= (1<<PE6);
				EICRB &= ~(0x03<<4);
				EICRB |= (state<<4);
				EIMSK |= 1<<INT6;
			break;
		
			case ExINT7:
				DDRE &= ~(1<<DDE7);
				PORTE |= (1<<PE7);
				EIMSK |= 1<<INT7;
				EICRB &= ~(3<<6);
				EICRB |= (state<<6);
			break;	
		}
		sei();
	#endif
}