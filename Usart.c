/*
 * Usart.c
 *
 * Created: 4/5/2018 4:38:21 PM
 *  Author: Mahmoud
 */ 
#include <avr/io.h>
#include "Usart.h"

void Usart_Initialization()
{
	UBRRL= BAUDRATE;											//Put baud rate into UBRR
	UCSRB|=(1U<<TXEN)|(1U<<RXEN);								//Enable RX and TX pins
	UCSRC|=(1U<<UCSZ1)|(1U<<UCSZ0)|(1U<<URSEL);					//8bit , select UCSRC
}

void Usart_Send_Character(unsigned char data)
{
	while (!((UCSRA)&(1U<<UDRE)));								//Wait until date register empty
	UDR=data;													//Send data
}

unsigned char Usart_Recieve_Character (void)
{
	while (!((UCSRA)&(1U<<RXC)));					        	//Wait until date register empty
	return UDR;													//Return received data to save
}

void Usart_Send_String(char* string)
{
	int i=0;
	
	while(string[i]!='\0')	
	{
		Usart_Send_Character(string[i]);
		i++;
	}
}

void Usart_Send_8bit_int(uint8_t data)
{
	while (!((UCSRA)&(1U<<UDRE)));								//Wait until date register empty
	UDR=data;													//Send data	
}

uint8_t Usart_Receive_8bit_int()
{
	while (!((UCSRA)&(1U<<RXC)));					        	//Wait until date register empty
	return UDR;													//Return received data to save
}