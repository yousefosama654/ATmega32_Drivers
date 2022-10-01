/*
 ============================================================================
 *  GPIO_Exercise.c
 *  Date: OCT 1, 2022
 *  Author: Yousef_Osama
 *  Description: THE EXERCISE OF THE LCD DRIVER
 ============================================================================
 */
#include "lcd.h"
#include<util/delay.h>
int main(void) {
	LCD_init();
	LCD_displayString("yousef");
	while (1) {
	}
}
