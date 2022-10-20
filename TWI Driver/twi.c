/*
 ============================================================================
 *  twi.c
 *  Date: OCT 20, 2022
 *  Author: Yousef_Osama
 *  Description: The Source File of TWI Driver
 ============================================================================
 */
#include"twi.h"
#include"avr/io.h"
#include"common_macros.h"
void TWI_init(const TWI_Config *config) {
	TWBR = config->SCKFactor;
	TWSR = config->twiPrescalar;
	TWAR = config->slaveAddress << 1;
	SET_BIT(TWCR, TWEN);
}
void TWI_start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
void TWI_stop(void) {
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	// no need for polling to leave the bus
}
void TWI_writeByte(uint8 data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT))
		;
}
uint8 TWI_readByteWithACK(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (BIT_IS_CLEAR(TWCR, TWINT))
		;
	return TWDR;
}
uint8 TWI_readByteWithNACK(void) {
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT))
		;
	return TWDR;
}
uint8 TWI_getStatus(void) {
	uint8 status = TWSR & 0xF8;
	return status;
}
