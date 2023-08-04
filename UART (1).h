#ifndef UART_H
#define UART_H

// parity
#define none 0
#define even 1
#define odd 2
// stop bits
#define STOP_BIT_1	      0
#define STOP_BIT_2		  1
//functions
#define _TX				  0
#define _RX				  1
#define _TX_RX			  2
//ports
#define COM0              0
#define COM1              1
// data length
#define WORD_LENGTH_5	  0
#define WORD_LENGTH_6	  1
#define WORD_LENGTH_7	  2
#define WORD_LENGTH_8	  3


void ConfigUART(uint8_t,unsigned int,uint8_t,uint8_t,uint8_t,uint8_t);
unsigned char Inputbin(uint8_t);
void Printbin(uint8_t,unsigned char);
void ExtPrintbin(uint8_t,uint8_t,unsigned char);
void ConfigExtPrintbin(uint8_t);


#endif