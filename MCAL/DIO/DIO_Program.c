/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */


/* include for every header file (DIO) */
#include "DIO_Interface.h"
#include "DIO_Private.h"

void MDIO_vSetPinDirection(u8 A_u8portNumber, u8 A_u8pinNumber, u8 A_u8dir)
{
	if (A_u8dir == INPUT)
	{
		switch(A_u8portNumber)
		{
		case PORT_A: CLR_BIT(DDRA,A_u8pinNumber); break;
		case PORT_B: CLR_BIT(DDRB,A_u8pinNumber); break;
		case PORT_C: CLR_BIT(DDRC,A_u8pinNumber); break;
		case PORT_D: CLR_BIT(DDRD,A_u8pinNumber); break;
		}
	}
	else if (A_u8dir == OUTPUT)
	{
		switch(A_u8portNumber)
		{
		case PORT_A: SET_BIT(DDRA,A_u8pinNumber); break;
		case PORT_B: SET_BIT(DDRB,A_u8pinNumber); break;
		case PORT_C: SET_BIT(DDRC,A_u8pinNumber); break;
		case PORT_D: SET_BIT(DDRD,A_u8pinNumber); break;
		}
	}else{
		/* Do nothing */
	}
}

/* DDRA = 90; */

void MDIO_vSetPortDirection(u8 A_u8portNumber, u8 A_u8dir)
{
	switch (A_u8portNumber){
	case PORT_A:
		DDRA = A_u8dir; break;
	case PORT_B:
		DDRB = A_u8dir; break;
	case PORT_C:
		DDRC = A_u8dir; break;
	case PORT_D:
		DDRD = A_u8dir; break;
	}
}

/* pin high/low */

void MDIO_vSetPinValue(u8 A_u8portNumber, u8 A_u8pinNumber, u8 A_u8val)
{
	//if it is output high
	if(A_u8val == HIGH){
		switch(A_u8portNumber){
		case PORT_A:
			//PORTA |= (1<<A_u8pinNumber);
			SET_BIT(PORTA, A_u8pinNumber);
			break;
		case PORT_B:
			//PORTB |= (1<<A_u8pinNumber);
			SET_BIT(PORTB, A_u8pinNumber);
			break;
		case PORT_C:
			//PORTC |= (1<<A_u8pinNumber);
			SET_BIT(PORTC, A_u8pinNumber);
			break;
		case PORT_D:
			//PORTD |= (1<<A_u8pinNumber);
			SET_BIT(PORTD, A_u8pinNumber);
			break;
		}
	}else if(A_u8val == LOW){
		switch(A_u8portNumber){
		case PORT_A:
			//PORTA &= ~(A_u8pinNumber);
			CLR_BIT(PORTA, A_u8pinNumber);
			break;
		case PORT_B:
			//PORTB &= ~(A_u8pinNumber);
			CLR_BIT(PORTB, A_u8pinNumber);
			break;
		case PORT_C:
			//PORTC &= ~(A_u8pinNumber);
			CLR_BIT(PORTC, A_u8pinNumber);
			break;
		case PORT_D:
			//PORTD &= ~(A_u8pinNumber);
			CLR_BIT(PORTD, A_u8pinNumber);
			break;
		}
	}else{
		/* Do nothing */
	}
}

/* port pins ===> val */
void MDIO_vSetPortValue(u8 A_u8portNumber, u8 A_u8Val)
{
	switch (A_u8portNumber){
	case PORT_A: PORTA = A_u8Val; break;
	case PORT_B: PORTB = A_u8Val; break;
	case PORT_C: PORTC = A_u8Val; break;
	case PORT_D: PORTD = A_u8Val; break;
	}
}

/* high ==> low, low ===> high */
void MDIO_vTogglePinValue(u8 A_u8portNumber, u8 A_u8pinNumber)
{
	switch(A_u8portNumber){
	case PORT_A:
		//PORTA ^= (1<<A_u8pinNumber);
		TOG_BIT(PORTA,A_u8pinNumber);
		break;
	case PORT_B:
		//PORTB ^= (1<<A_u8pinNumber);
		TOG_BIT(PORTB,A_u8pinNumber);
		break;
	case PORT_C:
		//PORTC ^= (1<<A_u8pinNumber);
		TOG_BIT(PORTC,A_u8pinNumber);
		break;
	case PORT_D:
		//PORTD ^= (1<<A_u8pinNumber);
		TOG_BIT(PORTD,A_u8pinNumber);
		break;
	}
}

/* return high/low */
u8 MDIO_U8GetPinValue(u8 A_u8portNumber, u8 A_u8pinNumber)
{
	u8 local_u8Value = 255;
	switch(A_u8portNumber){
	case PORT_A: local_u8Value =  GET_BIT(PINA,A_u8pinNumber);
	//((PINA>>A_u8pinNumber)&1);
	break;
	case PORT_B: local_u8Value =  GET_BIT(PINB,A_u8pinNumber);
	//((PINB>>A_u8pinNumber)&1);
	break;
	case PORT_C: local_u8Value = GET_BIT(PINC,A_u8pinNumber);
	//((PINC>>A_u8pinNumber)&1); //
	break;
	case PORT_D: local_u8Value = GET_BIT(PIND,A_u8pinNumber);
	//((PIND>>A_u8pinNumber)&1); //
	break;
	}
	return local_u8Value;
}
