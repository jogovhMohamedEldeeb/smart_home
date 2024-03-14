/*
 * main.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */

#include "APP/app.h"

#define F_CPU	8000000UL


u8 login_tries = 0;
u8 temp_value;
u16 ldr_value;
u8 temp_string[5];

int main(void){

	u8 login_tries = 0;
	u8 temp_value;
	u16 ldr_value;
	u8 temp_string[5];
	app_init();
	LOG("Welcome to Samrt Home\n\r");
	while(1){
		if(Read_Password()){
			LOG("Fail login!\n\r");
			login_tries++;
			if(MAX_LOGIN_TRIES <= login_tries)
				Halt_System();
			else{
				HLCD_vDisplayClear();
				HLCD_vSendString((u8*)"Try Again!");
				_delay_ms(500);
				HLCD_vDisplayClear();
				continue;
			}
		}
		else{
			LOG("Successful login !\n\r");
			HLCD_vDisplayClear();
			HLCD_vSendString((u8*)"You can Access!");
			_delay_ms(500);
			HLCD_vDisplayClear();
			break;
		}
	}
	HLCD_vSendString((u8*)"Temp");
	HLCD_vSendData_pos((u8)': ', STRINGS_ROW, SEPARATOR_COL);
	HLCD_vSendString((u8*)"Light");
	HLCD_vSendData_pos((u8)': ', VALUES_ROW, SEPARATOR_COL);
	GIE_vEnableInterrupts();
	while(1){
		LOG("------------------------------\n\r");
		temp_value = Get_Temperature_Value();
		ldr_value = Get_LDR_Value();
		HLCD_vSendString_pos(VALUE_REMOVE_STR, VALUES_ROW, TEMP_VAL_START);
		HLCD_vSendNumber_pos(temp_value, VALUES_ROW, TEMP_VAL_START);
		HLCD_vSendData((u8)'C');
		HLCD_vSendString_pos(VALUE_REMOVE_STR, VALUES_ROW, LIGHT_VAL_START);
		HLCD_vSendNumber_pos(ldr_value, VALUES_ROW, LIGHT_VAL_START);
		HLCD_vSendData((u8)'%');

		/* Convert temperature value to printable string */
		itoa(temp_value, (char*)temp_string, 10);
		if(TEMP_THRESHOLD < temp_value){
			LOG("Motor is on, temperature = ");
			LOG(temp_string);
			LOG("C!\n\r");
			Set_Motor_Value(Motor_ON);
		}
		else{
			/* If SW1 is not pressed */
			if(MDIO_U8GetPinValue(SW1_PORT, SW1_PIN)){
				LOG("Motor is off, temperature = ");
				LOG(temp_string);
				LOG("C!\n\r");
				Set_Motor_Value(Motor_OFF);
			}
			else{
				LOG("Cannot turn off motor, switch 1 is pressed!\n\r");
				LOG("Current temperature = ");
				LOG(temp_string);
				LOG("C!\n\r");
			}
		}

		/* Convert LDR value to printable string */
		itoa(ldr_value, (char*)temp_string, 10);
		if(LDR_THRESHOLD > ldr_value){
			LOG("Lamp is on, Light intensity = ");
			LOG(temp_string);
			LOG("%!\n\r");
			Set_Lamp_Value(Lamp_ON);
		}
		else{
			/* If SW2 is not pressed */
			if(MDIO_U8GetPinValue(SW2_PORT, SW2_PIN)){
				LOG("Lamp is off, Light intensity = ");
				LOG(temp_string);
				LOG("%!\n\r");
				Set_Lamp_Value(Lamp_OFF);
			}
			else{
				LOG("Cannot turn off lamp, switch 2 is pressed!\n\r");
				LOG("Current Light intensity = ");
				LOG(temp_string);
				LOG("%!\n\r");
			}
		}
		_delay_ms(1000);
	}
	return 0;
}
