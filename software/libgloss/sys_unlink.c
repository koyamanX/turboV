#include "libgloss_turboV.h"

int sys_unlink(const char *pathname) {
	errno = ENOENT;
	return -1;
}
