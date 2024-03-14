/*
 * EXTI_interface.h
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

/* Section : Includes */
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"


/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	enu_EXTI		INTx;
	enu_EXTI_MODES	INTx_MODE;
	void (*pf_Callback)(void);
}EXTI_cfg;
/* Section : Function Declarations */
void EXTI_vEnableEXTI(const EXTI_cfg *INTx);

void EXTI_vDisableEXTI(const EXTI_cfg *INTx);

#endif /* EXTI_EXTI_INTERFACE_H_ */
