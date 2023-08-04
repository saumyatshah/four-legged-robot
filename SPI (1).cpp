#include <avr/io.h>
#include "SPI.h"
 
 void SPI_Init(uint8_t Mode,uint8_t data_order,uint8_t clk_pol,uint8_t clk_phase,uint8_t clk_rate)
 {
	
	 if (data_order)
	 SPCR |= (1<<DORD);
	 else
	 SPCR &= ~(1<<DORD);
	 //------------------------------------------------
	 if(clk_pol)
	 SPCR |=(1<<CPOL);
	 else
	 SPCR &= ~(1<<CPOL);
	 //------------------------------------------------
	 if(clk_phase)
	 SPCR |=(1<<CPHA);
	 else
	 SPCR &= ~(1<<CPHA);
	 
	 switch (Mode)
	 {
		 case Master:
			
			DDR_SPI |= (1<<DD_MOSI)|(1<<DD_SS)|(1<<DD_SCK);
			SPCR |= (1<<MSTR);
			//-----------------------------------------------
			SPCR &= 0xFC;
			SPSR &=0xFE;
			switch(clk_rate)
			{
				case By16:
					SPCR |=0x01;
				break;
				case By64:
					SPCR |=0x02;
				break;
				case By128:
					SPCR |=0x03;
				break;
				case By2:
					SPSR |=0x01;
				break;
				case By8:
					SPSR |=0x01;
					SPCR |=0x01;
				break;
				case By32:
					SPSR |=0x01;
					SPCR |=0x02;
				break;

			}

		break;

		case Slave:
			DDR_SPI |=(1<<DD_MISO);
			SPCR &= ~(1<<MSTR);
		break;

	 }

	 SPCR |=(1<<SPE);
 
 }
 
 uint8_t  SPI_Communicate(uint8_t cData)
 {
	 SPDR = cData;
	 while(!(SPSR & (1<<SPIF)));
	 return SPDR;
 }