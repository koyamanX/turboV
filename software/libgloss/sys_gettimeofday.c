#include "libgloss_turboV.h"

int sys_gettimeofday(struct timeval *tv, struct timezone *tz) {
	errno = EFAULT;
	return -1;
}
