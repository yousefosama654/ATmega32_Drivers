/*
 ============================================================================
 *  GPIO_Exercise.c
 *  Date: Sep 26, 2022
 *  Author: Yousef_Osama
 *  Description: THE EXERCISE OF THE GPIO DRIVER
 ============================================================================
 */
#include "gpio.h"
#include <util/delay.h> /* To use the delay functions */
int main() {
	/* PA3 Input Pin */
	GPIO_setupPinDirection(PORTA_ID, PIN3_ID, PIN_INPUT);
	/* PA4 Input Pin */
	GPIO_setupPinDirection(PORTA_ID, PIN4_ID, PIN_INPUT);
	/* All PORTD pins are o/p pins */
	GPIO_setupPortDirection(PORTD_ID, PORT_OUTPUT);
	/* Turn OFF all LEDS */
	GPIO_writePort(PORTD_ID, 0);
	while (1) {
		/* Read PA3 Pin Value */
		if(GPIO_readPin(PORTA_ID, PIN3_ID))
		{
		/* Toggle All Even LEDS*/
			GPIO_writePort(PORTD_ID,0x55);
			_delay_ms(500);
			GPIO_writePort(PORTD_ID,0x00);
			_delay_ms(500);
		}
		/* Read PA4 Pin Value */
		if(GPIO_readPin(PORTA_ID, PIN3_ID))
		{
		/* Toggle All Odd LEDS*/
			GPIO_writePort(PORTD_ID,0xAA);
			_delay_ms(500);
			GPIO_writePort(PORTD_ID,0x00);
			_delay_ms(500);
		}
		else
		{
		/* Turn OFF all LEDS */
			GPIO_writePort(PORTD_ID,0x00);
		}
	}
	return 0;
}

