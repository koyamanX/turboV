#include "libgloss_turboV.h"
#include "uart.h"

int uart_putchar(int ch) {
	*UART_TXCTRL = 0x1;
	while(*UART_TXDATA & 0x80000000)
		asm volatile("nop");
	*UART_TXDATA = (char)ch;

	return (unsigned char )ch;
}
int uart_getchar(void) {

}
