#include "libgloss_turboV.h"
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
	errno = EFAULT;
	return -1;
}
