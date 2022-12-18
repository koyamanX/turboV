#define UART_TXDATA ((volatile unsigned int *)0x40000000)
#define UART_RXDATA ((volatile unsigned int *)0x40000004)
#define UART_TXCTRL ((volatile unsigned int *)0x40000008)
#define UART_RXCTRL ((volatile unsigned int *)0x4000000c)
#define UART_IE 	((volatile unsigned int *)0x40000010)
#define UART_IP 	((volatile unsigned int *)0x40000014)
#define UART_DIV 	((volatile unsigned int *)0x40000018)

void trap_handler(void) {
	asm volatile("mret");
}

void uart_init(void) {
	*UART_TXCTRL = 0x1;
}
int uart_putchar(int c) {
	while(*UART_TXCTRL & 0x80000000)
		asm volatile("nop");
	*UART_TXDATA = (char)c;

	return (unsigned int) c;
}
int uart_puts(const char *str) {
	while(*str != '\0') {
		uart_putchar(*str);
		str++;
	}
	uart_putchar('\n');

	return 0;
}

void main(void) {
	uart_init();
	uart_puts("Hello,World!");
}
