#include "usart.h"

int main(void) {
	uint8 Str[20];
	uint8 data;
	USART_ConfigType config = { DISABLED_PARITY, BIT_1_STOP_SELECT, 8, 9600 };
	USART_init(&config);
	while (1) {
//		data = USART_recieveByte(); /* Receive Byte from Terminal */
//		USART_sendByte(data); /* Re-send the received byte to Terminal */
		USART_recieveString(Str); /* Receive String from Terminal */
		USART_sendString(Str); /* Re-send the string to Terminal2 */
	}
}
