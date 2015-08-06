/*
 *
 *
 */

#include "../include/apue.h"
#include "../include/pr_wait.h"
#include "sys/wait.h"

int glob = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
	int var;
	pid_t pid;

	var = 88;
	write(STDOUT_FILENO, buf, sizeof(buf) - 1);
	printf("now begainning fork\n");
	pid = fork();
	switch (pid) {
		case -1://error
			err_sys("fork error\n");
			break;
		case 0://child
			printf("this is child\n");
			glob++;
			var++;
			break;
		default://parent;
			sleep(2);
			break;
	}

	printf("pid = %d; glob = %d; var = %d\n", getpid(), glob, var);

	exit(EXIT_SUCCESS);
}
