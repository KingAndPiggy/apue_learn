/*
 *
 *
 */

#include "../include/apue.h"
#include "../include/pr_wait.h"
#include "sys/wait.h"

int main(int argc, char *argv[])
{
	pid_t pid;

	printf("now begainning fork\n");
	pid = vfork();
	switch (pid) {
		case -1://error
			err_sys("fork error\n");
			break;
		case 0://child
			printf("This is child\n");
			sleep(2);
			_exit(0);
			break;
		default://parent;
			printf("parent\n");
			break;
	}

	exit(EXIT_SUCCESS);
}
