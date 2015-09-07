/*
 *使用siguspend 函数 避免竞争冒险现象 ， 避免Pause函数 由于时间问题带来的永远阻塞现象
 *Time:8-18
 *Author:Twopiggy
 */

#include "../../include/apue.h"
#include <signal.h>

static void sig_int(int signo);
int main(int argc, char *argv[])
{
	sigset_t newmask, oldmask, waitmask;

	pr_mask("program start:");
	if (signal(SIGINT, sig_int) == SIG_ERR) {
		err_sys("signal error: SIGINI");
	}
	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);

	/*
	 *Block SIGINT and save current signal mask
	 */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("sigprocmask error");
	pr_mask("in critical region:");
	/*
	 *
	 */
	if (sigsuspend(&waitmask) != -1)
		err_sys("siguspend error");
	pr_mask("after return from siguspend:");
	/*
	 *
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	pr_mask("program exit:");

	exit(0);
}

static void sig_int(int signo)
{
	pr_mask("\n in sig_int:");
}
