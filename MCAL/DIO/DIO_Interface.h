/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* library includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#define INPUT 0
#define OUTPUT 1

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7

#define HIGH 1
#define LOW 0
#define WRONG_INPUT 50

/* Description: Set pin direction (Output / input)
 * Arguments  : A_u8PortNumber, A_u8PinNumber, A_u8Dir
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 *  A_u8Dir        : 0 ===> input , 1===> output
 * Return type: void (Nothing)
 * */
void MDIO_vSetPinDirection(u8 A_u8portNumber, u8 A_u8pinNumber, u8 A_u8dir);
/* Description: Set port direction (Output / input)
 * Arguments  : A_u8PortNumber, A_u8Dir
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8Dir        : 0 - 255
 * Return type: void (Nothing)
 * */
void MDIO_vSetPortDirection(u8 A_u8portNumber, u8 A_u8dir);
/* Description: Set pin value/status (High / Low)
 * Arguments  : A_u8PortNumber, A_u8PinNumber, A_u8Value
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 *  A_u8Value      : 0 ===> Low , 1===> High
 * Return type: void (Nothing)
 * */
void MDIO_vSetPinValue(u8 A_u8portNumber, u8 A_u8pinNumber, u8 A_u8val);
/* Description: Set port value (High / Low)
 * Arguments  : A_u8PortNumber, A_u8Value
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8Value        : 0 - 255
 * Return type: void (Nothing)
 * */
void MDIO_vSetPortValue(u8 A_u8portNumber, u8 A_u8Val);
/* Description: get pin value/status (High / Low)
 * Arguments  : A_u8PortNumber, A_u8PinNumber
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 * Return type: u8 (value of the pin (0 --> low / 1--> high ))
 * */
u8 MDIO_U8GetPinValue(u8 A_u8portNumber, u8 A_u8pinNumber);
/* Description: toggle pin value/status (High / Low)
 * Arguments  : A_u8PortNumber, A_u8PinNumber
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 * Return type: void (Nothing)
 * */
void MDIO_vTogglePinValue(u8 A_u8portNumber, u8 A_u8pinNumber);


#endif /* DIO_INTERFACE_H_ */
