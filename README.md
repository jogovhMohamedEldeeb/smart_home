Description :
A smart home system that controls a motor fan and a lamp.
The system shall have an admin panel that requires the user to login on startup.
AȦer 3 failed login attempts, the system will halt and require a reset.
The system is connected to light and temperature sensors to sense the surrounding environment.
According to the sensorsʼ values, the system shall automatically turn on or off the fan and the lamp.
The system shall have a way to manually turn on/off the fan and the lamp.
The system shall send log messages to a terminal through UART, alternatively, a Bluetooth module can be used instead of the
terminal to inform the user about system actions.


Project Design:
The project is based on Layered Architecture and operates on a State Machine inside a Super Loop.

Peripherals used:
1-DIO
2-ADC
3-External Interrupts
4-UART

External devices used:
1-keypad
2-LCD
3-LM35
4-LDR
5-Switch
6-Lamp
7-Relay

