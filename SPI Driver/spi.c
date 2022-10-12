/*
 ============================================================================
 *  SPI.c
 *  Date: OCT 12, 2022
 *  Author: Yousef_Osama
 *  Description: The Source File of SPI Driver
 ============================================================================
 */
#include"spi.h"
#include"gpio.h"
#include"common_macros.h"
#include"avr/io.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Initialize the SPI device as Master.
 */
void SPI_initMaster() {
	GPIO_setupPinDirection(SPI_SS_PORT_ID, SPI_SS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SPI_MOSI_PORT_ID, SPI_MOSI_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SPI_MISO_PORT_ID, SPI_MISO_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(SPI_SCK_PORT_ID, SPI_SCK_PIN_ID, PIN_OUTPUT);
	SET_BIT(SPCR, MSTR);
	SET_BIT(SPCR, SPE);
}
/*
 * Description :
 * Initialize the SPI device as Slave.
 */
void SPI_initSlave() {
	GPIO_setupPinDirection(SPI_MOSI_PORT_ID, SPI_MOSI_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(SPI_MISO_PORT_ID, SPI_MISO_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SPI_SS_PORT_ID, SPI_SS_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(SPI_SCK_PORT_ID, SPI_SCK_PIN_ID, PIN_INPUT);
	CLEAR_BIT(SPCR, MSTR);
	SET_BIT(SPCR, SPE);
}
/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
uint8 SPI_sendRecieveByte(uint8 data) {
	SPDR = data;
	/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while (BIT_IS_CLEAR(SPSR, SPIF))
		;
	/*
	 * Note: SPIF flag is cleared by first reading SPSR (with SPIF set) which is done in the previous step.
	 * and then accessing SPDR like the below line.
	 */
	return SPDR;
}
/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(string s) {
	uint8 i = 0;
	uint8 received_data = 0;

	/* Send the whole string */
	while(s[i] != '\0')
	{
		/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		SPI_sendRecieveByte(s[i]);
		i++;
	}
}
/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_recieveString(uint8 *s) {
	uint8 i = 0;
	s[i] = SPI_sendRecieveByte(SPI_DEFAULT_DATA_VALUE);
	while (s[i] != '#') {
		i++;
		s[i] = SPI_sendRecieveByte(SPI_DEFAULT_DATA_VALUE);
	}
	s[i] = '\0';
}
