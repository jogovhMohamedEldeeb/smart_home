/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/ADC/ADC_Interface.h"
#include "LM35_Interface.h"

void HLM35_vInit(void){
	MADC_vInit();
}

u32 HLM35_vCallValue(void){
	u32 digital = MADC_u8GetDigitalValue(0);
	u32 analog = 5000*digital/1024;
	u32 temp = analog/10;
	return temp;
}
