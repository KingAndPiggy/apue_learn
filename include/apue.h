/*
 *error handl and proccess exit(status) handl
 *
 */
#ifndef __APUE_H__
#define __APUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <stdarg.h>

#define MAXLINE 4096 /*缓冲区大小*/
static void err_doit(int errnoflag, int errno_x, const char *fmt, va_list ap);
void err_sys(const char *fmt, ...);
void pr_wait(int status);

/*--------------------------------------------------------------
 *proccess error handler
 *------------------------------------------------------------*/
#include <error.h>
#include <errno.h>


void err_sys(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}
/*
 *fatal error related to a system call 致命错误相关到系统调用
 *printf a message, dump core, and terminate.
 */

void err_dump(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort(); /*core dump and terminate 核心转存与终止*/
	exit(1); /*should't get here */
}
/*
 *print a message and return to caller
 *caller specifies "errnoflag"
 */
static void err_doit(int errnoflag, int errno_x, const char *fmt, va_list ap)
{
	char buf[MAXLINE];
	
	vsnprintf(buf, MAXLINE - 1, fmt, ap);
	if(errnoflag) {
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) -1, ": %s", strerror(errno_x));
	}
	strcat(buf, "\n"); //add end
	fflush(stdout); /*in case stdout and stderr are the same*/
	fputs(buf, stderr); 
	fflush(NULL); /*flushes all stdio output streams*/
}
/*-----------------------------------------------------
 *进程退出状态处理
 *---------------------------------------------------*/
#include <sys/wait.h>

void pr_wait(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if (WIFSIGNALED(status)) 
		printf("abnormal termination, siganl number = %d%s\n", 
				WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : "");
#else 
				"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));	
}

/*--------------------------------------------------------
 *proccess signal
 *author:Mr king
 *-------------------------------------------------------*/
#include <signal.h>

#endif

