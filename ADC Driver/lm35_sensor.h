/*
 ============================================================================
 *  lm35_sensor.h
 *  Date: OCT 2, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of ADC Driver
 ============================================================================
 */
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_CHANNEL_ID                  2
#define LM35_SENSOR_MAX_VOLTAGE            1.5
#define LM35_SENSOR_MAX_TEMP               150
#include"std_types.h"
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_SENSOR_getTemperature(void);
#endif /* LM35_SENSOR_H_ */
