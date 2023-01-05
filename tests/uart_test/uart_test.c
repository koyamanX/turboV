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

int uart_putchar(int c) {
	while(*UART_TXDATA & 0x80000000)
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

void uart_enable(void) {
	*UART_TXCTRL = 0x1;
}
void uart_disable(void) {
	*UART_TXCTRL = 0x0;
}

#define SIM_EXIT ((volatile unsigned int *) 0x80001000)
#define OK 1
#define NG 2

void main(void) {
	uart_disable();
	for(int i = 0; i < 8; i++) {
		uart_putchar('0'+i);
	}
	if(!(*UART_TXDATA & 0x80000000)) {
		*SIM_EXIT = NG;
	}
	uart_enable();

	for(int i = 0; i < 1000; i++) {
		asm volatile("nop");
	}

	uart_puts("");
	uart_puts("Hello,world!!");

	*SIM_EXIT = OK;
}
