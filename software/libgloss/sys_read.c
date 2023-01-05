#include "libgloss_turboV.h"
#include "uart.h"

ssize_t sys_read(int fd, void *buf, size_t count) {
	size_t i;

	if((fd != STDIN_FILENO)) {
		errno = EBADF;
		return -1;
	}
	for(i = 0; i < count; i++) {
		((unsigned char *)buf)[i] = uart_getchar();
	}
	return i;
}
