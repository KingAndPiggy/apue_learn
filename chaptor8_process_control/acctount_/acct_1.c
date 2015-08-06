/*
 *8-14:进程会计，proccess account
 *time:2015-8-5
 *author:Mr king
 */
#include "../../include/apue.h"

int main(int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if ( pid != 0) {          /*parent*/
		sleep(2);
		exit(2);                   /* terminate with exit status 2*/
	}

	
	if ((pid = fork()) < 0)       /*firest child*/
		err_sys("fork error");
	else if ( pid != 0) {
		sleep(4);
		abort();
	}

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if ( pid != 0) {
		sleep(4);
		exit(7);
	}

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if ( pid != 0) {
		sleep(4);
		exit(1);
	}


}
