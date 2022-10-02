/*
 ============================================================================
 *  adc.h
 *  Date: OCT 2, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of ADC Driver
 ============================================================================
 */

#ifndef ADC_H_
#define ADC_H_
#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channelNum);
#endif /* ADC_H_ */
