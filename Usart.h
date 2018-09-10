/*
 * Usart.h
 *
 * Created: 4/5/2018 4:51:03 PM
 *  Author: Mahmoud
 */ 


#ifndef USART_H_
#define USART_H_


#define F_CPU (8000000UL)
#include <stdint.h>
#define BAUD	9600								// define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)			// set baud rate value for UBRR

void Usart_Initialization (void);					//function to initialize uart module

void Usart_Send_Character (unsigned char data);		//function to send character
unsigned char Usart_Recieve_Character (void);		//function to receive character 

void Usart_Send_String(char* string);				//function to send string

void Usart_Send_8bit_int(uint8_t data);				//function to send 8bit integer
uint8_t Usart_Receive_8bit_int(void);			    //function to receive 8bit integer

#endif /* USART_H_ */