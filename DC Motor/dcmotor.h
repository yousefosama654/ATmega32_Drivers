#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include"std_types.h"
#include "gpio.h"
#define DC_MOTOR_IN1_PORT_ID       PORTC_ID
#define DC_MOTOR_IN1_PIN_ID        PIN0_ID
#define DC_MOTOR_IN2_PORT_ID       PORTC_ID
#define DC_MOTOR_IN2_PIN_ID        PIN1_ID
typedef enum DC_MOTOR_State {
	STOP,CW,ACW
}DC_MOTOR_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DC_MOTOR_State state,uint8 speed);
#endif /* DCMOTOR_H_ */
