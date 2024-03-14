/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/ADC/ADC_Interface.h"
#include "LDR_Interface.h"

void HLDR_vInit(void){
	MADC_vInit();
}
u16 HLDR_vCallValue(void){
	u16 digital = MADC_u8GetDigitalValue(1);
	return digital;
}
