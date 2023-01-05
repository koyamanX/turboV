#include "libgloss_turboV.h"

int sys_fstat(int fd, struct stat *statbuf) {
	if((fd == STDOUT_FILENO) || (fd == STDERR_FILENO)) {
		statbuf->st_mode = S_IFCHR;
		return 0;
	}
	errno = ENOENT;
	return -1;
}

