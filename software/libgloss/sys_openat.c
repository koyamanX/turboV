#include "libgloss_turboV.h"

int sys_openat(int dirfd, const char *pathname, int flag, mode_t mode) {
	errno = ENOSYS;
	return -1;
}
