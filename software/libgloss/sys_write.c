#include "libgloss_turboV.h"
#include "uart.h"

ssize_t sys_write(int fd, const void *buf, size_t count) {
	size_t i;

	if((fd != STDOUT_FILENO) && (fd != STDERR_FILENO)) {
		errno = EBADF;
		return -1;
	}
	for(i = 0; i < count; i++) {
		uart_putchar(((unsigned char *)buf)[i]);
	}
	return i;
}
