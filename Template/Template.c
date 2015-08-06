/*
 *
 *
 */

#include "../include/apue.h"
#include "sys/wait.h"

int main(int argc, char *argv[])
{
	pid_t pid;

	printf("now begainning fork\n");
	pid = fork();
	switch (pid) {
		case -1://error
			err_sys("fork error\n");
			break;
		case 0://child
			break;
		default://parent;
			break;
	}

	exit(EXIT_SUCCESS);
}
