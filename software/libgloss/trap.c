#include "libgloss_turboV.h"
#include <machine/syscall.h>
#include <stdint.h>

int32_t syscall(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, int32_t syscall_id) {
	int32_t ret = -1;

	switch(syscall_id) {
		case SYS_write:
			ret = sys_write((int)arg0, (const void *)arg1, (size_t)arg2);
			break;
		case SYS_access:
			ret = sys_access((const char *)arg0, (int)arg1);
			break;
		case SYS_close:
			ret = sys_close((int) arg0);
			break;
		case SYS_faccessat:
			ret = sys_faccessat((int)arg0, (const char *)arg1, (int)arg2, (int)arg3);
			break;
		case SYS_fstatat:
			ret = sys_fstatat((int)arg0, (const char *)arg1, (struct stat *)arg2, (int)arg3);
			break;
		case SYS_fstat:
			ret = sys_fstat((int)arg0, (struct stat *)arg1);
			break;
		case SYS_link:
			ret = sys_link((const char *)arg0, (const char *)arg1);
			break;
		case SYS_lseek:
			ret = sys_lseek((int)arg0, (off_t)arg1, (int)arg2);
			break;
		case SYS_lstat:
			ret = sys_lstat((const char *)arg0, (struct stat *)arg1);
			break;
		case SYS_openat:
			ret = sys_openat((int)arg0, (const char *)arg1, (int)arg2, (mode_t)arg3);
			break;
		case SYS_open:
			ret = sys_open((const char *)arg0, (mode_t)arg1);
			break;
		case SYS_stat:
			ret = sys_stat((const char *)arg0, (struct stat *)arg1);
			break;
		case SYS_unlink:
			ret = sys_unlink((const char *)arg0);
			break;
		case SYS_gettimeofday:
			ret = sys_gettimeofday((struct timeval *)arg0, (struct timezone *)arg1);
			break;
		case SYS_read:
			ret = sys_read((int)arg0, (void *)arg1, (size_t)arg2);
			break;
		case SYS_exit: /* no-break */
		default:
			sys_exit((int)arg0);
			break;
	}
	return ret;
}
