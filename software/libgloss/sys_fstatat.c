#include "libgloss_turboV.h"

int sys_fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags) {
	errno = ENOENT;
	return -1;
}
