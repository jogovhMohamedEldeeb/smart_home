/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#ifndef MCAL_ATMEGA32_GIE_GIE_INTERFACE_H_
#define MCAL_ATMEGA32_GIE_GIE_INTERFACE_H_

/********************* FILE INCLUDES *********************/
#include "GIE_config.h"
#include "GIE_private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

/********************* FUNCTION PROTOTYPES *********************/

// This function is responsible for enabling GIE for interrupts
void GIE_vEnableInterrupts();

// This function is responsible for disabling GIE for interrupts
void GIE_vDisableInterrupts();

#endif /* MCAL_ATMEGA32_GIE_GIE_INTERFACE_H_ */
