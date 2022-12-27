#include "libgloss_turboV.h"
#include <sys/times.h>

clock_t times(struct tms *buf) {
	errno = EFAULT;
	return -1;
}
