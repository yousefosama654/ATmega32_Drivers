/*
 ============================================================================
 *  lm35_sensor.c
 *  Date: OCT 2, 2022
 *  Author: Yousef_Osama
 *  Description: The Source File of ADC Driver
 ============================================================================
 */
#include"adc.h"
#include"lm35_sensor.h"
#include"std_types.h"
uint8 LM35_SENSOR_getTemperature(void) {
	uint16 ADC_value=ADC_readChannel(SENSOR_CHANNEL_ID);
return (uint8)(((uint32)ADC_value*LM35_SENSOR_MAX_TEMP*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LM35_SENSOR_MAX_VOLTAGE));
}
