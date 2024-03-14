/*
 * app.h
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
//#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../HAL/LDR/LDR_Interface.h"
#include "../HAL/LM35/LM35_Interface.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "../HAL/KPD/KPD_interfcae.h"
#include "../HAL/LCD/LCD_interface.h"

typedef enum{
	Lamp_OFF,
	Lamp_ON
}enu_LampControl;

typedef enum{
	Motor_OFF,
	Motor_ON
}enu_MotorControl;

extern UART_tcfgInitialize UART1;


#define LOG(__str)	UART_vSendString((u8*)__str)

#define MAX_LOGIN_TRIES		3
#define TEMP_THRESHOLD		30
#define LDR_THRESHOLD		50
#define MAX_SIZEOFPASSWORD  4
#define STRINGS_ROW			1
#define VALUES_ROW			2
#define SEPARATOR_COL		8
#define TEMP_VAL_START		1
#define LIGHT_VAL_START		9
#define MAX_ADC_VAL			1024.0
#define VALUE_REMOVE_STR	((s8*)"    ")
#define MOTOR_PORT			PORT_A
#define MOTOR_PIN			3
#define LAMP_PORT			PORT_A
#define LAMP_PIN			2
#define SW1_PORT			PORT_D
#define SW2_PORT			PORT_D
#define SW1_PIN				2
#define SW2_PIN				3



void app_init(void);
u8 Read_Password(void);
void sys_welcome();
u8 Get_Temperature_Value(void);
u8 Get_LDR_Value(void);
void Set_Lamp_Value(enu_LampControl _val);
void Set_Motor_Value(enu_MotorControl _val);
void Halt_System(void);


#endif /* APP_APP_H_ */
