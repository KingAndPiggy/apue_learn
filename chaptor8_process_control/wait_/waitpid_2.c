/*
 *创建多个进程使用waitpid监听进程到结束
 *
 */

#include "../../include/apue.h"
#include "../../include/pr_wait.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid1, pid2, w_pid;

	printf("-------begain:fork-------\n");
	pid1 = fork();
	switch (pid1) {
		case -1:/*error*/
			exit(EXIT_FAILURE);
			break;
		case 0:/*child*/
			printf("proccess 1 is execing....:%d\n", getpid());
			sleep(2);
			break;
		default:/*parent*/
			pid2 = fork();
			switch (pid2) {
				case -1:/*error*/
					exit(EXIT_FAILURE);
					break;
				case 0:/*child*/
					printf("proccess 2 is execing....:%d\n", getpid());
					sleep(4);
					break;
				default:/*parent*/
					break;
			}
			break;
	}
	if(pid1 != 0 && pid2 != 0) {
		int status;
		while((w_pid = waitpid(0, &status, WNOHANG)) == 0) {
			printf("waiting proccess over....\n");
			sleep(1);
		}
		printf("pid of over poccess:%d :", (int)w_pid);
		pr_wait(status);
	}

	exit(EXIT_SUCCESS);
}
