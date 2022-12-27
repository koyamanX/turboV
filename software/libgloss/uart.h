#ifndef UART_H
#define UART_H

#define UART_TXDATA ((volatile unsigned int *)0x40000000)
#define UART_RXDATA ((volatile unsigned int *)0x40000004)
#define UART_TXCTRL ((volatile unsigned int *)0x40000008)
#define UART_RXCTRL ((volatile unsigned int *)0x4000000c)
#define UART_IE 	((volatile unsigned int *)0x40000010)
#define UART_IP 	((volatile unsigned int *)0x40000014)
#define UART_DIV 	((volatile unsigned int *)0x40000018)

int uart_putchar(int ch);
int uart_getchar(void);

#endif
