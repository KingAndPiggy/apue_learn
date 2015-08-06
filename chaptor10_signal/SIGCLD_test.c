/*
 *test the charactor of signal SIGCLD 
 *
 */

#include "../include/apue.h"

static void sig_cld(int signo);


int main(int argc, char *argv[])
{
	pid_t pid;

	if (signal(SIGCLD, sig_cld) == SIG_ERR)
		perror("signal error");
	pid = fork();
	switch (pid) {
		case -1:
			err_sys("fork error");
		case 0:
			sleep(2);
			_exit(0);
		default:
			break;
	}
	pause();
	exit(0);
}

static void sig_cld(int signo)
{
	pid_t pid;
	int status;

	printf("signal SIGCLD received\n");
	if (signal(SIGCLD, sig_cld) == SIG_ERR)
		perror("signal error");
	if ((pid = wait(&status)) < 0)
		err_sys("wait error");
	printf("wait pid = %d\n", pid);
	pr_wait(status);
}

