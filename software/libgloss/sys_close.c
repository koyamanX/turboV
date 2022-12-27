#include "libgloss_turboV.h"

int sys_close(int fd) {
	errno = EBADF;
	return -1;
}
