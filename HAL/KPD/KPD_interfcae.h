/*
 * KPD_interface.h
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#define KPD_PORT PORT_B

void HKPD_Init(void);
u8 HKPD_U8GetPressedKey(void);

#endif /* KPD_INTERFACE_H_ */
