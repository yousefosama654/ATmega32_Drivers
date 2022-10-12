/*
 ============================================================================
 *  SPI.h
 *  Date: OCT 12, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of SPI Driver
 ============================================================================
 */
#ifndef SPI_H_
#define SPI_H_
#include"std_types.h"
/*******************************************************************************
 *                         Definitions                                         *
 *******************************************************************************/
#define SPI_MOSI_PORT_ID            PORTB_ID
#define SPI_MOSI_PIN_ID				PIN5_ID

#define SPI_MISO_PORT_ID			PORTB_ID
#define SPI_MISO_PIN_ID				PIN6_ID

#define SPI_SS_PORT_ID				PORTB_ID
#define SPI_SS_PIN_ID				PIN4_ID

#define SPI_SCK_PORT_ID				PORTB_ID
#define SPI_SCK_PIN_ID				PIN7_ID
/*
 * Default SPI data value used in case we need to receive a byte from the other device,
 * without need to send a data to it
 */
#define SPI_DEFAULT_DATA_VALUE 0xFF
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the SPI device as Master.
 */
void SPI_initMaster();
/*
 * Description :
 * Initialize the SPI device as Slave.
 */
void SPI_initSlave();
/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
uint8 SPI_sendRecieveByte(uint8 data);
/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(string s);
/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_recieveString(uint8 *s);
#endif /* SPI_H_ */
