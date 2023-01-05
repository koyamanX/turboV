#ifndef LIBGLOSS_TURBOV_H
#define LIBGLOSS_TURBOV_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

ssize_t sys_write(int fd, const void *buf, size_t count);
void sys_exit(int status);
int sys_access(const char *pathname, int mode);
int sys_close(int fd);
int sys_faccessat(int dirfd, const char *pathname, int mode, int flags);
int sys_fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags);
int sys_fstat(int fd, struct stat *statbuf);
int sys_link(const char *oldpath, const char *newpath);
off_t sys_lseek(int fd, off_t offset, int whence);
int sys_lstat(const char *pathname, struct stat *statbuf);
int sys_openat(int dirfd, const char *pathname, int flag, mode_t mode);
int sys_open(const char *pathname, int flags);
int sys_stat(const char *pathname, struct stat *statbuf);
int sys_unlink(const char *pathname);
int sys_gettimeofday(struct timeval *tv, struct timezone *tz);
ssize_t sys_read(int fd, void *buf, size_t count);

#include <errno.h>
#undef errno
extern int errno;

#endif
