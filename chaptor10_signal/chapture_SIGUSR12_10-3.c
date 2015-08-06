/*
 *capture SIGUSR1 SIGUSR2
 *Time:15-8-6
 *Author:Mr king
 */
#include "../include/apue.h"

static void sig_usr(int);

int main(int argc, char *argv[])
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) 
		err_sys("signal error");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR) 
		err_sys("signal error");
	for( ; ; )
		pause();
}

static void sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else 
		err_dump("received signal %d\n", signo);
}
