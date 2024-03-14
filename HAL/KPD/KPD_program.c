/*
 * KPD_program.c
 *
 *  Created on: 14 Mar 2024
 *      Author: mohamed eldeeb
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/io.h>
#include <util/delay.h>
#include "KPD_interfcae.h"

u8 static keys[4][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', 'x'},
        {'1', '2', '3', '-'},
        {'C', '0', '=', '+'}
    };

void HKPD_Init(void){
	//MDIO_vSetPortDirection(KPD_PORT, 0x0FU);
	//MDIO_vSetPortValue(KPD_PORT,0xFFU);
	DDRB = 0x0FU;
	PORTB = 0xFFU;
}
u8 HKPD_U8GetPressedKey(void){

    u8 local_u8Key = 0;

    for (u8 row = 0; row < 4; row++) {
        // Set the current row to LOW
        MDIO_vSetPinValue(KPD_PORT, row, LOW);
        // Check each column for a pressed key
        for (u8 col = 4; col < 8; col++) {
            // Check if the column pin is LOW (key pressed)
            if (MDIO_U8GetPinValue(KPD_PORT, col) == 0) {
                _delay_ms(10); // Debounce delay (adjust as needed)
                // Check again to confirm the key press
                if (MDIO_U8GetPinValue(KPD_PORT, col) == 0) {
                    // Wait for key release
                    while (MDIO_U8GetPinValue(KPD_PORT, col) == 0);
                    // Key press confirmed
                    local_u8Key = keys[row][col - 4];
                    // Release the row (set it back to HIGH)
                    MDIO_vSetPinValue(KPD_PORT, row, HIGH);
                    // Return the detected key
                    return local_u8Key;
                }
            }
        }
        // Release the current row (set it back to HIGH)
        MDIO_vSetPinValue(KPD_PORT, row, HIGH);
    }
    // No key pressed
    return local_u8Key;
}

