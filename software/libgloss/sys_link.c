#include "libgloss_turboV.h"

int sys_link(const char *oldpath, const char *newpath) {
	errno = EMLINK;
	return -1;
}
