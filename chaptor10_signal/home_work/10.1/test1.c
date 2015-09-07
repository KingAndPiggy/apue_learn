/*
 *
 *
 */

#include <apue.h>

static void sig_usr(int signo);

int main(int argc, char *argv[])
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("SIGUSR1 error");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_sys("SIGUSR2 error");

	for( ; ; )
		pause();
}

static void sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("recived SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("recived SIGUSR2\n");
	else 
		printf("error\n");
}
