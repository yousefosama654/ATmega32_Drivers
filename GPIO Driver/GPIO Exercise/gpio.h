/*
 * gpio.h
 *  Created on: Sep 26, 2022
 *      Author: Yousef_Osama
 * Description: Header file for the AVR GPIO driver
 */
#ifndef GPIO_H_
#define GPIO_H_
#include "std_types.h"
#define NUM_OF_PORTS 4
#define NUM_OF_PINS_PER_PORT 8
/*define the port id to encapsulate the registers from the user*/
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
/*define the pin id for every pin the a port*/
#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7
/*******************************************************************************
 *                              Type Definitions                               *
 *******************************************************************************/
typedef enum {
	PIN_INPUT,PIN_OUTPUT
} GPIO_PinDirectionType;
typedef enum {
	PORT_INPUT=0X00,PORT_OUTPUT=0XFF
} GPIO_PortDirectionType;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
▪ Description:
• Setup the direction of the required pin input/output.
• If the input port number or pin number are not correct, The function
will not handle the request
*/
void GPIO_setupPinDirection(uint8 PORT_ID , uint8 PIN_ID,GPIO_PinDirectionType PinDirection);
/*
▪ Description:
• Write the value Logic High or Logic Low on the required pin.
• If the input port number or pin number are not correct,The function will not handle the request.
• If the pin is input, this function will
enable/disable the internal pull-up resistor.*/
void GPIO_writePin(uint8 PORT_ID, uint8 PIN_ID,uint8 value);
/*
▪ Description:
• Read and return the value for the required pin, it should be Logic High or Logic Low.
• If the input port number or pin number are not correct,
The function will return Logic Low.*/
uint8 GPIO_readPin(uint8 PORT_ID, uint8 PIN_ID);
/*
▪ Description:
• Setup the direction of the required port all pins input/output.
• If the direction value is PORT_INPUT all pins in this port should be input pins.
• If the direction value is PORT_OUTPUT all pins in this port should be output pins.
• If the input port number is not correct, The function will not handle the request.*/
void GPIO_setupPortDirection(uint8 PORT_ID,GPIO_PortDirectionType PortDirection );
/*
▪ Description:
• Write the value on the required port.
• If any pin in the port is output pin the value will be written.
• If any pin in the port is input pin this will
activate/deactivate the internal pull-up
resistor.
• If the input port number is not correct,
The function will not handle the request*/
void GPIO_writePort(uint8 PORT_ID, uint8 value);
/*
▪ Description:
• Read and return the value of the required port.
• If the input port number is not correct,
The function will return ZERO value.*/
uint8 GPIO_readPort(uint8 PORT_ID);
#endif /* GPIO_H_ */
