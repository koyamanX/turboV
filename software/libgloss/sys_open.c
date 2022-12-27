#include "libgloss_turboV.h"

int sys_open(const char *pathname, int flags) {
	errno = ENOSYS;
	return -1;
}
