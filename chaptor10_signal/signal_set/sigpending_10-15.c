/*
 *
 *
 */

#include "../../include/apue.h"

static void sig_quit(int);

int main(int argc, char *argv[])
{
	sigset_t newmask, oldmask, pendmask;

	if (signal(SIGQUIT, sig_quit) == SIG_ERR) 
		err_sys("can't catch SIGQUIT");

	/*
	 *Block SIGQUIT and have current signal mask
	 *阻塞SIGQUIT信号 并获取当前信号屏蔽集
	 */
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) 
		err_sys("SIG_BLOCK error");
	
	sleep(5);  /*SIGQUIT here will remain pending*/

	if (sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");

	/*
	 *reset signal mask which unblocks SIGOUT
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("sigprocmask error");
	printf("SIGOUT unblocked\n");

	sleep(5);
	exit(0);
}

static void sig_quit(int signo)
{
	printf("caught SIGOUT\n");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}
