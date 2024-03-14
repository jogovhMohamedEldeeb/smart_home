/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

/*
 * Init (voltage source - prescalar - auto trigger - Data direction)
 * read (Enable ADC - Start conversion - wait for flag - return reading)
 * */

void MADC_vInit(void){
	/* voltage source */
	SET_BIT(ADMUX, REFS0); // ADMUX = 6 //set
	CLR_BIT(ADMUX, REFS1); // ADMUX = 7 //clear
	/* Data direction : Right */
	CLR_BIT(ADMUX, ADLAR); // ADMUX = 5 //clear
	/* no auto trigger */
	CLR_BIT(ADCSRA, ADATE); // ADCSRA = 5 //clear
	/* Prescalar ==> /8 */
	SET_BIT(ADCSRA, ADPS2); //ADCSRA = 2 //set
	SET_BIT(ADCSRA, ADPS1); //ADCSRA = 1 //set
	CLR_BIT(ADCSRA, ADPS0); //ADCSRA = 0 //clear
}
u16 MADC_u8GetDigitalValue(u8 A_u8Channel){
	A_u8Channel &= CHANNEL_MASK; /* channel 5 bits */
	ADMUX &= ADMUX_MASK; /* save last 3 bits, clear right 5 bits */
	ADMUX |= A_u8Channel;
	/* ENABLE ADC */
	SET_BIT(ADCSRA, ADEN);
	/* Start conversion */
	SET_BIT(ADCSRA,ADSC);
	/* pooling on flag */
	while (GET_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA, ADIF);
	/* reading value */
	return ADC;
}





