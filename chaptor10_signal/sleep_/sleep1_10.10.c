/*
 *使用alarm() 函数和pause函数实现到简单sleep1函数
 *存在多种问题
 *Time:15-8-6
 *Author: Mr king
 */

#include "../../include/apue.h"

static void sig_alrm(int signo)
{
	/*nothing to do, just return to wake up the paushe*/
}

unsigned int sleep1(unsigned int nsecs)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR) 
		return (nsecs);
	alarm(nsecs);
	pause();
	return(alarm(0));
}
int main(int argc, char *argv[])
{
	printf("hello world\n");
	sleep1(2);
	printf("hello world\n");
	
	return 0;
}

