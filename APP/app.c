/*
 * app.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */


#include "app.h"

#define SYSTEM_PSW		1122
UART_tcfgInitialize UART1;
void SW1_Callback(void){
	/*
	 * Check for SW1 status,
	 * if pressed -> turn on motor
	 * if not pressed -> turn off motor
	 */
	if(!MDIO_U8GetPinValue(SW1_PORT, SW1_PIN)){
		Set_Motor_Value(Motor_ON);
		LOG("\n\r***Switch 1 pressed! Manually turning on motor!\n\r\n\r");
	}
	else{
		Set_Motor_Value(Motor_OFF);
		LOG("\n\r***Switch 1 released! Manually turning off motor!\n\r\n\r");
	}
}

void SW2_Callback(void){
	/*
	 * Check for SW2 status,
	 * if pressed -> turn on lamp
	 * if not pressed -> turn off lamp
	 */
	if(!MDIO_U8GetPinValue(SW2_PORT, SW2_PIN)){
		Set_Lamp_Value(Lamp_ON);
		LOG("\n\r***Switch 2 pressed! Manually turning on lamp!\n\r\n\r");
	}
	else{
		Set_Lamp_Value(Lamp_OFF);
		LOG("\n\r***Switch 2 released! Manually turning off lamp!\n\r\n\r");
	}
}

void app_init(void){
	/* Motor Pin Init */
	MDIO_vSetPinDirection(MOTOR_PORT, MOTOR_PIN, OUTPUT);
	MDIO_vSetPinValue(MOTOR_PORT, MOTOR_PIN, HIGH);

	/* Lamp Pin Init */
	MDIO_vSetPinDirection(LAMP_PORT, LAMP_PIN, OUTPUT);
	MDIO_vSetPinValue(LAMP_PORT, LAMP_PIN, HIGH);

	/* ADC Init */
	MADC_vInit();

	/* Switches and EXTI Init */
	MDIO_vSetPinDirection(SW1_PORT, SW1_PIN, INPUT);
	MDIO_vSetPinDirection(SW2_PORT, SW2_PIN, INPUT);
	MDIO_vSetPinValue(SW1_PORT, SW1_PIN, HIGH);
	MDIO_vSetPinValue(SW2_PORT, SW2_PIN, HIGH);
	EXTI_cfg SW1_EXTI = {.INTx = INT0, .INTx_MODE = MODE_LOGICAL_CHANGE, .pf_Callback = SW1_Callback};
	EXTI_cfg SW2_EXTI = {.INTx = INT1, .INTx_MODE = MODE_LOGICAL_CHANGE, .pf_Callback = SW2_Callback};
	EXTI_vEnableEXTI(&SW1_EXTI);
	EXTI_vEnableEXTI(&SW2_EXTI);

	/* Keypad Init */
	HKPD_Init();

	/* LCD Init */
	HLCD_vInit();

	/* UART Init */
	UART1.GLOBAL_tcfgCharSize = CHAR_8_BITS;
	UART1.GLOBAL_tcfgParityState = PARITY_DISABLED;
	UART1.GLOBAL_tcfgStopBits = STOP_BITS_1;
	UART1.GLOBAL_tcfgUartBaudRate1X = UART_BR1X_9600;
	UART1.GLOBAL_tcfgUartClkMode = UART_ASYNCHRONOUS;
	UART1.GLOBAL_tcfgUartCommMode = UART_1X_SPEED;
	UART1.GLOBAL_tcfgUartInterrupt = UART_INTERRUPT_DISABLED;
	UART_vInit(&UART1);
	UART_vEnable(&UART1);
	u8 cc;
	while(1){
		cc = UART_u8ReceiveData();
		UART_vSendData(cc);
		if(cc == 'C'){
			UART_vSendString((u8*)"\n\r\n\r\n\r");
			break;
		}
	}
}

u8 Read_Password(void){
	/*
	 * Read password from keypad
	 * If password is correct, return 0
	 * If password is incorrect, return 1
	 */
    u8 str[] = "Enter Password: ";
    //u8 strinvalid[] = "invalid character";
    u8 keypad_entry;
    u32 password = 0;
    HLCD_vSendString(str);
	HLCD_vSetCursorPosition(2, 1);

    while (1) {
        keypad_entry = HKPD_U8GetPressedKey();

        if (keypad_entry == '=') {
            break;
        } else if ((keypad_entry >= '0') && (keypad_entry <= '9')) {
            HLCD_vSendData(keypad_entry);
            _delay_ms(50);
            password += (keypad_entry - 48);
            password *= 10;
        } else { /* Do Nothing */ }
    }

    password /= 10;

    // Check if the entered password is correct
    u8 ret_val = (password == SYSTEM_PSW) ? 0 : 1;
    return ret_val;

}

u8 Get_Temperature_Value(void){
	u8 ret_val = HLM35_vCallValue();
	return ret_val;
}

u8 Get_LDR_Value(void){
	double ret_val;
	u16 adc_value = HLDR_vCallValue();
	adc_value++;
	ret_val = (adc_value / MAX_ADC_VAL) * 100; // Get percentage
	return (u8)ret_val;
}

void Set_Lamp_Value(enu_LampControl _val){
	u8 state = (_val == Lamp_OFF) ? HIGH : LOW;
	MDIO_vSetPinValue(LAMP_PORT, LAMP_PIN, state);
}

void Set_Motor_Value(enu_MotorControl _val){
	u8 state = (_val == Motor_OFF) ? HIGH : LOW;
	MDIO_vSetPinValue(MOTOR_PORT, MOTOR_PIN, state);
}

void Halt_System(void){
	/*
	 * Halt system
	 */
	HLCD_vDisplayClear();
	HLCD_vSendString((u8*)"System is stoped!");
	LOG("System is stoped!\n\r");
	LOG("Reason: Invalid login \n\r");
	UART_vDisable(&UART1);
	while(1);
}
