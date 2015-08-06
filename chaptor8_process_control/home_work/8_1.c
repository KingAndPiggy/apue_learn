/*
 *
 *
 */
#include "../../include/apue.h"
#include <sys/types.h>

void close_std(void);
int main(int argc, char *argv[])
{
	pid_t pid;
	char name[] = "wanghui";

	pid = vfork();
	switch (pid) {
		case -1:
			err_sys("vfork error");
		case 0:
			sleep(1);
			atexit(close_std);
			printf("child:pid = %d\n", getpid());
			fflush(stdout);
			exit(1);
		default:
			break;
	}
	if (printf("parent:pid = %d\n", getpid()) < 0) {
		write(STDOUT_FILENO, name, strlen(name));	
		err_sys("printf error");
	}

	exit(0);
}

void close_std(void)
{
	fclose(stdout);
	fclose(stdin);
}
