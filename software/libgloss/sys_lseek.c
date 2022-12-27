#include "libgloss_turboV.h"

off_t sys_lseek(int fd, off_t offset, int whence) {
	if((fd == STDOUT_FILENO) || (fd == STDERR_FILENO)) {
		return 0;
	}
	errno = EBADF;
	return -1;
}
