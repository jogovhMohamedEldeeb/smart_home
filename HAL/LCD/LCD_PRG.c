/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

/* lib */
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"
/* Any driver .h file you need */
/* mcal */
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_INT.h"


/* init - send command - send data */
void HLCD_vInit(void){
	/* RS output */
	MDIO_vSetPinDirection(CONTROL_PORT,RS,OUTPUT);
	/* RW output */
	MDIO_vSetPinDirection(CONTROL_PORT,RW,OUTPUT);
	/* En output */
	MDIO_vSetPinDirection(CONTROL_PORT,EN,OUTPUT);
	/* data port output */
	MDIO_vSetPortDirection(DATA_PORT,OUTPUT);
	_delay_ms(50);
	/* Function set */
	HLCD_vSendCommand(FUNCTION_SET);
	_delay_ms(1);
	/* DISPLAY_ON */
	HLCD_vSendCommand(DISPLAY_ON);
	_delay_ms(1);
	/* DISPLAY_CLEAR */
	HLCD_vSendCommand(DISPLAY_CLEAR);
	_delay_ms(3);
	/* ENTRY_MODE_SET */
	HLCD_vSendCommand(ENTRY_MODE_SET);
	_delay_ms(1);
}
void HLCD_vSendCommand(u8 A_u8Command){
	/* RS = 0 (Command mode) */
	MDIO_vSetPinValue(CONTROL_PORT,RS,LOW);
	/* RW = 0 (Write mode) */
	MDIO_vSetPinValue(CONTROL_PORT,RW,LOW);
	/* send command through the port */
	MDIO_vSetPortValue(DATA_PORT,A_u8Command);
	/* Enable sequence */
	MDIO_vSetPinValue(CONTROL_PORT,EN,HIGH);
	_delay_ms(1);
	MDIO_vSetPinValue(CONTROL_PORT,EN,LOW);
	_delay_ms(1);
}
void HLCD_vSendData(u8 A_u8Data){
	/* RS = 1 (Data mode) */
	MDIO_vSetPinValue(CONTROL_PORT,RS,HIGH);
	/* RW = 0 (Write mode) */
	MDIO_vSetPinValue(CONTROL_PORT,RW,LOW);
	/* send command through the port */
	MDIO_vSetPortValue(DATA_PORT,A_u8Data);
	/* Enable sequence */
	MDIO_vSetPinValue(CONTROL_PORT,EN,HIGH);
	_delay_ms(1);
	MDIO_vSetPinValue(CONTROL_PORT,EN,LOW);
	_delay_ms(1);
}
void HLCD_vSendString(u8 * A_ptrToString){

	while (*A_ptrToString!='\0'){
		HLCD_vSendData(*A_ptrToString);
		A_ptrToString++;
	}
}
/* 0-1 (0 - 15) */
void HLCD_vMoveTo(u8 A_u8Row, u8 A_u8Col){
	switch(A_u8Row){
	case 0:
		HLCD_vSendCommand(128 + A_u8Col);break;
	case 1:
		HLCD_vSendCommand(192 + A_u8Col);break;
	}
}
void HLCD_vDisplayClear(void){
	HLCD_vSendCommand(DISPLAY_CLEAR);
}
s32 static HLCD_s32ReverseNumber(s32 A_s32Number){
	s32 local_s32Rev = 1;
	while (A_s32Number != 0){
		s32 local_s32Digit = A_s32Number%10;
		local_s32Rev = local_s32Rev*10 + local_s32Digit;
		A_s32Number /= 10;
	}
	return local_s32Rev;
}
void HLCD_vSendNumber(s32 A_s32Number){
	if (A_s32Number < 0){
		HLCD_vSendData('-');
		A_s32Number *= -1;
	}
	if (A_s32Number == 0){
		HLCD_vSendData('0');
		return;
	}
	// reverse number
	s32 cur = HLCD_s32ReverseNumber(A_s32Number);
	// apply alogrithm
	while (cur != 1){
		HLCD_vSendData(cur%10 + '0'); //===> HLCD_vSendData('1') '1' ===> 1 + '0'
		cur /= 10;
	}
}
void HLCD_vSetCursorPosition(s32 A_s32RowNumber,s32 A_s32ColumnNumber){
	A_s32ColumnNumber--;
	if(A_s32RowNumber == 1){
		HLCD_vSendCommand(ROW1_Address + A_s32ColumnNumber);
	}else if(A_s32RowNumber == 2){
		HLCD_vSendCommand(ROW2_Address + A_s32ColumnNumber);
	}
}

void HLCD_vSendData_pos(u8 A_u8Data ,s32 A_s32RowNumber,s32 A_s32ColumnNumber){
	HLCD_vSetCursorPosition(A_s32RowNumber, A_s32ColumnNumber);
	HLCD_vSendData(A_u8Data);
}

void HLCD_vSendString_pos(s8 *A_s8String ,s32 A_s32RowNumber,s32 A_s32ColumnNumber){
	HLCD_vSetCursorPosition(A_s32RowNumber, A_s32ColumnNumber);
	HLCD_vSendString(A_s8String);
}

void HLCD_vSendNumber_pos(s32 A_s32Number ,s32 A_s32RowNumber,s32 A_s32ColumnNumber){
	HLCD_vSetCursorPosition(A_s32RowNumber, A_s32ColumnNumber);
	HLCD_vSendNumber(A_s32Number);
}
