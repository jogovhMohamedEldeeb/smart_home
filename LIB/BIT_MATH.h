/*
 * BIT_MATH.h
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#ifndef SERVICES_BIT_MATH_H_
#define SERVICES_BIT_MATH_H_

#define SET_BIT(REG, PIN)		(REG |= (1U<<PIN))
#define CLR_BIT(REG, PIN)		(REG &= ~(1U<<PIN))
#define TOG_BIT(REG, PIN)		(REG ^= (1U<<PIN))
#define GET_BIT(REG, PIN)		((REG>>PIN) & 0x01)


#endif /* SERVICES_BIT_MATH_H_ */
