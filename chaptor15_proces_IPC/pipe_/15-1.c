/*
 *
 *
 */

#include "../../include/apue.h"

int main(void)
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd) < 0)
		err_sys("pipe error");
	pid = fork();
	switch (pid) {
		case -1: err_sys("fork error");
		case  0: write(STDOUT_FILENO, "child:", 7);
				 close(fd[1]);
				 n = read(fd[0], line, MAXLINE);
				 write(STDOUT_FILENO, line, n);
		default: write(STDOUT_FILENO, "parent:", 8);
				 close(fd[0]);
				 write(fd[1], "hello world\n", 12);
				 break;
	}

	if (pid > 0) {
		pid_t child;
		int status;

		child = wait(&status);
		pr_wait(status);
	}
	exit(0);
}
