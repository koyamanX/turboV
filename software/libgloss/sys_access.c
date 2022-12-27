#include "libgloss_turboV.h"

int sys_access(const char *pathname, int mode) {
	errno = ENOENT;
	return -1;
}

