#include "libgloss_turboV.h"

int sys_faccessat(int dirfd, const char *pathname, int mode, int flags) {
	errno = ENOENT;
	return -1;
}

