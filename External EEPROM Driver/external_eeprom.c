/*
 ============================================================================
 *  external_eeprom.c
 *  Date: OCT 20, 2022
 *  Author: Yousef_Osama
 *  Description: The Source File of EEPROM Driver
 ============================================================================
 */
#include "external_eeprom.h"
#include "twi.h"
uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data) {
	TWI_start();
	if (TWI_getStatus() != TWI_START)
		return ERROR;
	TWI_writeByte((uint8) (0xA0 | ((u16addr & 0x0700) >> 7)));
	if (TWI_getStatus() != TWI_MT_SLA_W_ACK)
		return ERROR;
	TWI_writeByte((uint8) (u16addr));
	if (TWI_getStatus() != TWI_MT_DATA_ACK)
		return ERROR;
	TWI_writeByte(u8data);
	if (TWI_getStatus() != TWI_MT_DATA_ACK)
		return ERROR;
	TWI_stop();
	return SUCCESS;
}
uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data) {
	TWI_start();
	if (TWI_getStatus() != TWI_START)
		return ERROR;
	TWI_writeByte((uint8) ((0xA0) | ((u16addr & 0x0700) >> 7)));
	if (TWI_getStatus() != TWI_MT_SLA_W_ACK)
		return ERROR;
	TWI_writeByte((uint8) (u16addr));
	if (TWI_getStatus() != TWI_MT_DATA_ACK)
		return ERROR;
	TWI_start();
	if (TWI_getStatus() != TWI_REP_START)
		return ERROR;
	TWI_writeByte((uint8) ((0xA0) | ((u16addr & 0x0700) >> 7) | 1));
	if (TWI_getStatus() != TWI_MT_SLA_R_ACK)
		return ERROR;
	*u8data = TWI_readByteWithNACK();
	if (TWI_getStatus() != TWI_MR_DATA_NACK)
		return ERROR;
	TWI_stop();
	return SUCCESS;
}
