#ifndef SPI_H
#define SPI_H

//------------------------------------spi pins and ddr---------------------------------------
#define DDR_SPI    DDRB

#if defined (__AVR_ATmega128__)||defined (__AVR_ATmega128A__)
	#define DD_MOSI		DDRB2
	#define DD_MISO		DDRB3
	#define DD_SS		DDRB0
	#define DD_SCK		DDRB1
#endif

#if defined (__AVR_ATmega32A__) || defined(__AVR_ATmega16__)
	#define DD_MOSI		DDB5
	#define DD_MISO		DDB6
	#define DD_SS		DDB4
	#define DD_SCK		DDB7
#endif

#if defined (__AVR_ATmega16A__)
#define DD_MOSI		DDB5
#define DD_MISO		DDB6
#define DD_SS		DDB4
#define DD_SCK		DDB7
#endif

#if defined (__AVR_ATmega8__)
	#define DD_MOSI		DDB3
	#define DD_MISO		DDB4
	#define DD_SS		DDB2
	#define DD_SCK		DDB5
#endif

//----------------------data order-------------------------------
#define MSB_first  0
#define LSB_first  1
//---------------------clock polarity ---------------------------//what edge is leading
#define  rise 0   //rising   0
#define  fall 1 //falling  1
//-----------------------clock phase ------------------------------//edge on which sampling takes place
#define leading   0
#define trailing  1
//--------------------------mode -------------------------------------
#define Master 0
#define Slave  1
//------------------------clock rate--------------------------------
#define By4   0
#define By16  1
#define By64  2 
#define By128 3
#define By2   4
#define By8   5
#define By32  6


void SPI_Init(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t);
uint8_t SPI_Communicate(uint8_t);
#endif