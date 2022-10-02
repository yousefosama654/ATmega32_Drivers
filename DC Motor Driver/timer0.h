/*
 ============================================================================
 *  timer0.h
 *  Date: OCT 3, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of TIMER_0 Driver
 ============================================================================
 */
#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TIMER0_MAX_VALUE 255
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum {
	NORMAL_MODE, COMPARE_MODE, FAST_PWM_MODE
} Timer_Mode;
typedef enum {
	NORMAL_PORT = 0, NON_INVERTING_MODE = 2, INVERTING_MODE = 3
} PWM_Mode;
typedef enum {
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_CLOCK_8,
	F_CPU_CLOCK_64,
	F_CPU_CLOCK_256,
	F_CPU_CLOCK_1024
} Timer_Clock;
typedef struct {
	Timer_Mode timer_mode;
	PWM_Mode pwm_mode;
	Timer_Clock clock;
} Timer_Config;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the TIMER_0 driver.
 */
void Timer0_init(const Timer_Config *Config_Ptr);
 /*
  * Description :
  *  Setup the compare value based on the required input duty cycle.
  */
void Timer0_PWM_Start(uint8 duty_cycle_percentage);
/*
 * Description :
 * Function responsible for De_initialize the TIMER_0 driver.
 */
void TIMER0_deinit();
#endif /* TIMER0_H_ */
