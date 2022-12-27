#include "libgloss_turboV.h"

int sys_stat(const char *pathname, struct stat *statbuf) {
	errno = EACCES;
	return -1;
}
