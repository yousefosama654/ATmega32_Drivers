/*
 ============================================================================
 *  twi.h
 *  Date: OCT 20, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of TWI Driver
 ============================================================================
 */
#include"std_types.h"
#ifndef TWI_H_
#define TWI_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TWI_START   			0X08 /* start has been sent */
#define TWI_REP_START 			0X10 /* repeated start */
#define TWI_MT_SLA_W_ACK		0X18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK		0X40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK			0X28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK			0X50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK		0X58 /* Master received data but doesn't send ACK to slave. */
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	F_CPU_CLOCK,F_CPU_CLOCK_4,F_CPU_CLOCK_16,F_CPU_CLOCK_64
}TWI_preScaler;
typedef struct {
	TWI_preScaler twiPrescalar;
	uint8 slaveAddress;
	uint8 SCKFactor;
} TWI_Config;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TWI_init(const TWI_Config * config);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readByteWithACK(void);
uint8 TWI_readByteWithNACK(void);
uint8 TWI_getStatus(void);
#endif /* TWI_H_ */
