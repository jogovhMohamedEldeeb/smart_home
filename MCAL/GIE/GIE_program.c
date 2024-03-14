/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#include "GIE_interface.h"

// This function is responsible for enabling GIE for interrupts
void GIE_vEnableInterrupts(){
	SET_BIT(SREG_REG, 7);
}

// This function is responsible for disabling GIE for interrupts
void GIE_vDisableInterrupts(){
	CLR_BIT(SREG_REG, 7);
}
