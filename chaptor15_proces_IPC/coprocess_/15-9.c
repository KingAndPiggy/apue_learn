/*
 *parent----------->fd1[1]----fd1[0]---------->child
 *parent<-----------fd2[0]----fd2[1]<----------child
 *
 */
#include "../../include/apue.h"


void sig_pipe(int signo);  /*signal process func*/

int main(int argc, char *argv[])
{
	int n, fd1[2], fd2[2];
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd1) < 0 || pipe(fd2) < 0)
		err_sys("pipe error");

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid > 0) {
		close(fd1[0]);
		close(fd2[1]);
		while(fgets(line, MAXLINE, stdin) != NULL) {
			n = strlen(line);//计算line的字符数
			if (write(fd1[1], line, n) != n) //向管道写入数据
				err_sys("write error");
			if ((n = read(fd2[0], line, MAXLINE)) < 0) //从管道读出数据
				err_sys("read error from pipe");
			if (n == 0) {
				fprintf(stderr, "child closed pipe\n");
				break;
			}
			line[n] = 0;
			if (fputs(line, stdout) == EOF)//输出结果
				err_sys("fputs error to stdout");
		}
	}
	else {
		close(fd1[1]);
		close(fd2[0]);
		//从定向
		if (fd1[0] != STDIN_FILENO) {
			if (dup2(fd1[0], STDIN_FILENO) != STDIN_FILENO)
				err_sys("dup2 error");
			close(fd1[0]);
		}
		if (fd2[1] != STDOUT_FILENO) {
			if (dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO)
				err_sys("dup2 error");
			close(fd2[1]);
		}

		if (execl("./15-8", "15-8", (char *)0) < 0)
			err_sys("execl error");
	}

	exit(0);
}
