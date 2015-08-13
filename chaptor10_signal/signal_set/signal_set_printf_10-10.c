/*
 *
 *
 */

#include "../../include/apue.h"
#include <errno.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	sigset_t sigset, oldmask;

	if (sigemptyset(&sigset) < 0) 
		err_sys("initialization sigset error");
	if (sigaddset(&sigset, SIGINT) < 0) 
		err_sys("sigaddset error");
	if (sigaddset(&sigset, SIGALRM) < 0) 
		err_sys("sigaddset error");

	sigprocmask(SIG_BLOCK, &sigset,&oldmask);
	pr_mask("hello world");
	exit(EXIT_SUCCESS);
}
