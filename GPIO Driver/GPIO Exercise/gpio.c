/*
 *  gpio.c
 *  Created on: Sep 26, 2022
 *  Author: Yousef_Osama
 *  Description: source file for the AVR GPIO driver
 */
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */

/*
 ▪ Description:
 • Setup the direction of the required pin input/output.
 • If the input port number or pin number are not correct, The function
 will not handle the request
 */
void GPIO_setupPinDirection(uint8 PORT_ID, uint8 PIN_ID,
		GPIO_PinDirectionType PinDirection) {

	if (PORT_ID > NUM_OF_PORTS || PIN_ID > NUM_OF_PINS_PER_PORT) {
		/*do nothing*/
	} else {
		switch (PORT_ID) {
		case PORTA_ID:
			if (PinDirection == PIN_INPUT) {
				CLEAR_BIT(DDRA, PIN_ID);
			} else {
				SET_BIT(DDRA, PIN_ID);
			}
			break;
		case PORTB_ID:
			if (PinDirection == PIN_INPUT) {
				CLEAR_BIT(DDRB, PIN_ID);
			} else {
				SET_BIT(DDRB, PIN_ID);
			}
			break;
		case PORTC_ID:
			if (PinDirection == PIN_INPUT) {
				CLEAR_BIT(DDRC, PIN_ID);
			} else {
				SET_BIT(DDRC, PIN_ID);
			}
			break;
		case PORTD_ID:
			if (PinDirection == PIN_INPUT) {
				CLEAR_BIT(DDRD, PIN_ID);
			} else {
				SET_BIT(DDRD, PIN_ID);
			}
			break;
		}
	}
}
/*
 ▪ Description:
 • Write the value Logic High or Logic Low on the required pin.
 • If the input port number or pin number are not correct,The function will not handle the request.
 • If the pin is input, this function will
 enable/disable the internal pull-up resistor.*/
void GPIO_writePin(uint8 PORT_ID, uint8 PIN_ID, uint8 value) {
	if (PORT_ID > NUM_OF_PORTS || PIN_ID > NUM_OF_PINS_PER_PORT) {
		/*do nothing*/
	} else {
		switch (PORT_ID) {
		case PORTA_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTA, PIN_ID);
			} else {
				SET_BIT(PORTA, PIN_ID);
			}
			break;
		case PORTB_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTB, PIN_ID);
			} else {
				SET_BIT(PORTB, PIN_ID);
			}
			break;
		case PORTC_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTC, PIN_ID);
			} else {
				SET_BIT(PORTC, PIN_ID);
			}
			break;
		case PORTD_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTD, PIN_ID);
			} else {
				SET_BIT(PORTD, PIN_ID);
			}
			break;
		}
	}
}
/*
 ▪ Description:
 • Read and return the value for the required pin, it should be Logic High or Logic Low.
 • If the input port number or pin number are not correct,
 The function will return Logic Low.*/
uint8 GPIO_readPin(uint8 PORT_ID, uint8 PIN_ID) {
	if (PORT_ID > NUM_OF_PORTS || PIN_ID > NUM_OF_PINS_PER_PORT) {
		return LOGIC_LOW;
	} else {
		switch (PORT_ID) {
		case PORTA_ID:
			if (BIT_IS_SET(PORTA, PIN_ID)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if (BIT_IS_SET(PORTB, PIN_ID)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if (BIT_IS_SET(PORTC, PIN_ID)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if (BIT_IS_SET(PORTD, PIN_ID)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		}
	}
}
/*
 ▪ Description:
 • Setup the direction of the required port all pins input/output.
 • If the direction value is PORT_INPUT all pins in this port should be input pins.
 • If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 • If the input port number is not correct, The function will not handle the request.*/
void GPIO_setupPortDirection(uint8 PORT_ID,
		GPIO_PortDirectionType PortDirection) {
	if (PORT_ID > NUM_OF_PORTS) {
		/*Do Nothing*/
	} else {
		switch (PORT_ID) {
		case PORTA_ID:
			DDRA = PortDirection;
			break;
		case PORTB_ID:
			DDRB = PortDirection;
			break;
		case PORTC_ID:
			DDRC = PortDirection;
			break;
		case PORTD_ID:
			DDRD = PortDirection;
			break;
		}
	}
}
/*
 ▪ Description:
 • Write the value on the required port.
 • If any pin in the port is output pin the value will be written.
 • If any pin in the port is input pin this will
 activate/deactivate the internal pull-up
 resistor.
 • If the input port number is not correct,
 The function will not handle the request*/
void GPIO_writePort(uint8 PORT_ID, uint8 value) {
	if (PORT_ID > NUM_OF_PORTS) {
		/*do nothing*/
	} else {
		switch (PORT_ID) {
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}
/*
 ▪ Description:
 • Read and return the value of the required port.
 • If the input port number is not correct,
 The function will return ZERO value.*/
uint8 GPIO_readPort(uint8 PORT_ID) {

	if (PORT_ID > NUM_OF_PORTS)
		return LOGIC_LOW;
	else {
		switch (PORT_ID) {
		case PORTA_ID:
			return PORTA;
			break;
		case PORTB_ID:
			return PORTB;
			break;
		case PORTC_ID:
			return PORTC;
			break;
		case PORTD_ID:
			return PORTD;
			break;
		}
	}

}
