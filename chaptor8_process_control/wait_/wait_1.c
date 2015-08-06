/*
 *
 *
 */

#include "../../include/apue.h"
#include "../../include/pr_wait.h"
#include "sys/wait.h"

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;

	printf("now begainning fork\n");
	pid = fork();
	switch (pid) {
		case -1://error
			err_sys("fork error\n");
			break;
		case 0://child
			sleep(2);
			break;
		default://parent;
			break;
	}
	if (pid > 0) {
		printf("begainning wait\n");
		if (wait(&status) != pid) {
			err_sys("wait error\n");
		}
		pr_wait(status);
	}

	exit(EXIT_SUCCESS);
}
