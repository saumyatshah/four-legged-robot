#include <avr/io.h>
#include "UART.h"
#include <avr/interrupt.h>

unsigned char uart0tx[4],uart1tx[4];
uint8_t uart0txdone[4],uart1txdone[4];

// function to initialize UART
 //UBBR = (F_CPU/(16*baud))-1  define it in your main and pass it as argument;
void ConfigUART(uint8_t com,unsigned int UBBR,uint8_t function,uint8_t length,uint8_t stop_bit,uint8_t parity)
{
	#if defined (__AVR_ATmega128__)||defined (__AVR_ATmega128A__)
	  if (com == COM0)
	  {
		  UBRR0H = (unsigned char)(UBBR>>8);
		  UBRR0L = (unsigned char)UBBR;                         //set baud rate
		  
		//  UBRR0L = 103UL;
	    //  UBRR0H = 0UL;
        
		  UCSR0C &= ~(1<<UMSEL0);
		  UCSR0B &= ~(1<<UCSZ02);
		  //set function
	
		  if(function == _TX)
			UCSR0B |= (1<<TXEN0);
		  else if (function == _RX)
			UCSR0B |= (1<<RXEN0);
		  else if(function == _TX_RX)
			UCSR0B |= (1<<TXEN0)|(1<<RXEN0);
		  // set parity
		  UCSR0C &= ~(3<<UPM00);
		  if(parity == odd)
			UCSR0C |= (1<<UPM01)|(1<<UPM00);
		  else if(parity == even)
			UCSR0C |= (1<<UPM01);
		  
		  if (stop_bit == STOP_BIT_2)
			UCSR0C |= (1<<USBS0);
		  else
			UCSR0C &= ~(1<<USBS0);
		  //set data length
		  UCSR0C |= (3<<UCSZ00);
		  switch (length)
		  {
			  case WORD_LENGTH_5:
					UCSR0C &= ~(3<<UCSZ00);
				break;
			  case WORD_LENGTH_6:
					UCSR0C &= ~(1<<UCSZ01);
			  break;
			  case WORD_LENGTH_7:
					UCSR0C &= ~(1<<UCSZ00);
			  break;
		  }
	  
	  } 
	  
	  else
	  {
		  UBRR1H = (unsigned char)(UBBR>>8);
		  UBRR1L = (unsigned char)UBBR;                         //set baud rate
		  UCSR1C &= ~(1<<UMSEL1);
		  UCSR1B &= ~(1<<UCSZ12);
		  //set function
		  if(function == _TX)
			UCSR1B |= (1<<TXEN1);
		  else if (function == _RX)
			UCSR1B |= (1<<RXEN1);
		  else if(function == _TX_RX)
			UCSR1B |= (1<<TXEN1)|(1<<RXEN1);
		  // set parity
		  UCSR1C &= ~(3<<UPM10);
		  if(parity == odd)
			UCSR1C |= (1<<UPM11)|(1<<UPM10);
		  else if(parity == even)
			UCSR1C |= (1<<UPM11);
		  
		  if (stop_bit == STOP_BIT_2)
			UCSR1C |= (1<<USBS1);
		  else
			UCSR1C &= ~(1<<USBS1);
		  //set data length
		  UCSR1C |= (3<<UCSZ10);
		  switch (length)
		  {
			  case WORD_LENGTH_5:
				  UCSR1C &= ~(3<<UCSZ10);
			  break;
			  case WORD_LENGTH_6:
				  UCSR1C &= ~(1<<UCSZ11);
			  break;
			  case WORD_LENGTH_7:
				  UCSR1C &= ~(1<<UCSZ10);
			  break;
		  }

	  }
	  
	#else
		UBRRH = (uint8_t)(UBBR>>8);
		UBRRL = (uint8_t)(UBBR);
		UCSRC &= ~(1<<UMSEL);
		UCSRB &= ~(1<<UCSZ2);
		//set function 
		if(function == _TX)
			{UCSRB |= (1<<TXEN);}
		else if (function == _RX)
			{UCSRB |= (1<<RXEN);}
		else if(function == _TX_RX)
			{UCSRB |= (1<<TXEN)|(1<<RXEN);}
		// set parity
		UCSRC &= ~(3<<UPM0);
		if(parity == odd)	
			{UCSRC |= (1<<UPM1)|(1<<UPM0);}
		else if(parity == even)
		    {UCSRC |= (1<<UPM1);}
		
		if (stop_bit == STOP_BIT_2)
		    {UCSRC |= (1<<USBS);}
		else	
			{UCSRC &= ~(1<<USBS);}
		//set data length
		UCSRC |= (3<<UCSZ0);
		switch (length)
		{
			case WORD_LENGTH_5:
				UCSRC &= ~(3<<UCSZ0);
				break;
			case WORD_LENGTH_6:
				UCSRC &= ~(1<<UCSZ1);
				break;
			case WORD_LENGTH_7:
				UCSRC &= ~(1<<UCSZ0);
				break; 
		}
	#endif
}

// function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION


void Printbin(uint8_t com,unsigned char data)
{
	#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
		switch(com)
		{
			case COM0:
				while (!( UCSR0A & (1<<UDRE0)));            // wait while register is free
				UDR0 = data;
				break;
			case COM1:
				while (!( UCSR1A & (1<<UDRE1)));            // wait while register is free
				UDR1 = data;
				break;
		}
	#else	
		while (!( UCSRA & (1<<UDRE)));            // wait while register is free
		UDR = data;                             // load data in the register
	#endif
}


// function to receive data
unsigned char Inputbin(uint8_t com)
{
	#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
	switch(com)
	{
		case COM0:
			while (!( UCSR0A & (1<<RXC0)));            // wait while register is free
			return UDR0;
		break;
		case COM1:
		while (!( UCSR1A & (1<<RXC1)));            // wait while register is free
			return UDR1;
		break;
	}
	#else
		while(!(UCSRA & (1<<RXC)));           // wait while data is being received
		return UDR;                             // return 8-bit data
	#endif
}

void ConfigExtPrintbin(uint8_t channel)
{
	#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
		switch (channel)
		{
			case COM0:
				UCSR0B |= (1<<UDRIE0);
			break;
			case COM1:
				UCSR1B |= (1<<UDRIE1);
			break;
		}
		
	#else
		UCSRB |= (1<<UDRIE);
	#endif
}


void ExtPrintbin(uint8_t channel,uint8_t variable,unsigned char value)
{
	#if defined (__AVR_ATmega128__)||defined (__AVR_ATmega128A__)
	switch(channel)	{
		//-----------------------------------
		case COM0:
		switch(variable)	{
			//--------------------------------
			case 1:
			if(UCSR0A & (1<<UDRE0))	{
				UDR0=value;
			}
			else	{
				uart0tx[0] = value;
				uart0txdone[0] = 1;
			}
			break;
			//--------------------------------
			case 2:
			if(UCSR0A & (1<<UDRE0))	{
				UDR0=value;
			}
			else	{
				uart0tx[1] = value;
				uart0txdone[1] = 1;
			}
			break;
			//--------------------------------
			case 3:
			if(UCSR0A & (1<<UDRE0))	{
				UDR0=value;
			}
			else	{
				uart0tx[2] = value;
				uart0txdone[2] = 1;
			}
			break;
			//--------------------------------
			case 4:
			if(UCSR0A & (1<<UDRE0))	{
				UDR0=value;
			}
			else	{
				uart0tx[3] = value;
				uart0txdone[3] = 1;
			}
			break;
			//--------------------------------
		}
		break;
		//------------------------------------
		case COM1:
		switch(variable)	{
			//--------------------------------
			case 1:
			if(UCSR1A & (1<<UDRE1))	{
				UDR1=value;
			}
			else	{
				uart1tx[0] = value;
				uart1txdone[0] = 1;
			}
			break;
			//--------------------------------
			case 2:
			if(UCSR1A & (1<<UDRE1))	{
				UDR1=value;
			}
			else	{
				uart1tx[1] = value;
				uart1txdone[1] = 1;
			}
			break;
			//--------------------------------
			case 3:
			if(UCSR1A & (1<<UDRE1))	{
				UDR1=value;
			}
			else	{
				uart1tx[2] = value;
				uart1txdone[2] = 1;
			}
			break;
			//--------------------------------
			case 4:
			if(UCSR1A & (1<<UDRE1))	{
				UDR1=value;
			}
			else	{
				uart1tx[3] = value;
				uart1txdone[3] = 1;
			}
			break;
			//--------------------------------
		}
		break;
	}
	//----------------------------------
	#else
	switch(variable)	{
		//--------------------------------
		case 1:
		if(UCSRA & (1<<UDRE))	{
			UDR = value;
		}
		else	{
			uart0tx[0] = value;
			uart0txdone[0] = 1;
		}
		break;
		//--------------------------------
		case 2:
		if(UCSRA & (1<<UDRE))	{
			UDR=value;
		}
		else	{
			uart0tx[1] = value;
			uart0txdone[1] = 1;
		}
		break;
		//--------------------------------
		case 3:
		if(UCSRA & (1<<UDRE))	{
			UDR=value;
		}
		else	{
			uart0tx[2] = value;
			uart0txdone[2] = 1;
		}
		break;
		//--------------------------------
		case 4:
		if(UCSRA & (1<<UDRE))	{
			UDR=value;
		}
		else	{
			uart0tx[3] = value;
			uart0txdone[3] = 1;
		}
		break;
	}
	#endif
}

#if defined (__AVR_ATmega128__)||defined (__AVR_ATmega128A__)
ISR(USART0_UDRE_vect)	
{
	static uint8_t txcount = 0;
	uint8_t done = 1,count = 0;
	while(done && (count < 4))
	{
		if(txcount == 0)
		{
			txcount = 1;
			count++;
			if(uart0txdone[0] == 1)
			{
				if(!(UCSR0A & 0x20))
				{
					UDR0 = uart0tx[0];
					uart0txdone[0] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 1)
		{
			txcount = 2;
			count++;
			if(uart0txdone[1] == 1)
			{
				if(!(UCSR0A & 0x20))
				{
					UDR0 = uart0tx[1];
					uart0txdone[1] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 2)
		{
			txcount = 3;
			count++;
			if(uart0txdone[2] == 1)
			{
				if(!(UCSR0A & 0x20))
				{
					UDR0 = uart0tx[2];
					uart0txdone[2] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 3)
		{
		
			txcount = 0;
			count++;
			if(uart0txdone[3] == 1)
			{
				if(!(UCSR0A & 0x20))
				{
					UDR0 = uart0tx[3];
					uart0txdone[3] = 0;
				}
				done = 0;
			}
		}
	
	}
}

ISR(USART1_UDRE_vect)	
{
	static uint8_t txcount = 0;
	uint8_t done = 1,count = 0;
	while(done && (count < 4))
	{
		if(txcount == 0)
		{
			txcount = 1;
			count++;
			if(uart1txdone[0] == 1)
			{
				if(!(UCSR1A & 0x20))
				{
					UDR1 = uart1tx[0];
					uart1txdone[0] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 1)
		{
			txcount = 2;
			count++;
			if(uart1txdone[1] == 1)
			{
				if(!(UCSR1A & 0x20))
				{
					UDR1 = uart1tx[1];
					uart1txdone[1] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 2)
		{
			txcount = 3;
			count++;
			if(uart1txdone[2] == 1)
			{
				if(!(UCSR1A & 0x20))
				{
					UDR1 = uart1tx[2];
					uart1txdone[2] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 3)
		{
		
			txcount = 0;
			count++;
			if(uart1txdone[3] == 1)
			{
				if(!(UCSR1A & 0x20))
				{
					UDR1 = uart1tx[3];
					uart1txdone[3] = 0;
				}
				done = 0;
			}
		}
	
	}
}

#else

ISR(USART_UDRE_vect)	
{
	static uint8_t txcount = 0;
	uint8_t done = 1,count = 0;
	while(done && (count < 4))
	{
		if(txcount == 0)	
		{
			txcount = 1;
			count++;
			if(uart0txdone[0] == 1)	
			{
				if(!(UCSRA & 0x20))	
				{
					UDR = uart0tx[0];
					uart0txdone[0] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 1)	
		{
			txcount = 2;
			count++;
			if(uart0txdone[1] == 1)	
			{
				if(!(UCSRA & 0x20))	
				{
					UDR = uart0tx[1];
					uart0txdone[1] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 2)
		{
			txcount = 3;
			count++;
			if(uart0txdone[2] == 1)	
			{
				if(!(UCSRA & 0x20))
				{
					UDR = uart0tx[2];
					uart0txdone[2] = 0;
				}
				done = 0;
			}
		}
		else if(txcount == 3)
		{
			
			txcount = 0;
			count++;
			if(uart0txdone[3] == 1)
			{
				if(!(UCSRA & 0x20))
				{
					UDR = uart0tx[3];
					uart0txdone[3] = 0;
				}
				done = 0;
			}
		}
	
   }
}
#endif 