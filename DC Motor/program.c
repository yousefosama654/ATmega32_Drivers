#include<util/delay.h>
#include"avr/io.h"
#include"timer0.h"
#include"dcmotor.h"
int main() {
	while (1) {
		Timer_Config config =
				{ FAST_PWM_MODE, NON_INVERTING_MODE, F_CPU_CLOCK_8 };
		DDRA &= 0xF8;
		DDRC |= 0x03;
		PORTC &= 0xFC;
		Timer0_init(&config);
		DcMotor_Init();
		while (1) {
			/* check if the first push button at PA0 is pressed/not */
			if (PINA & (1 << PA0)) {
				// Rotate the motor --> clock wise
				DcMotor_Rotate(CW, 100);
			}

			/* check if the second push button at PA1 is pressed/not */
			else if (PINA & (1 << PA1)) {
				// Rotate the motor --> anti-clock wise
				DcMotor_Rotate(ACW, 50);
			}

			/* check if the third push button at PA2 is pressed/not */
			else if (PINA & (1 << PA2)) {
				// Stop the motor
				DcMotor_Rotate(STOP, 0);
			}
		}
	}
}
