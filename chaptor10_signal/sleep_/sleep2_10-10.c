/*
 *使用alarm() 函数和pause函数实现到简单sleep2函数
 *存在多种问题
 *Time:15-8-6
 *Author: Mr king
 */

#include "../../include/apue.h"
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
	longjmp(env_alrm, 1);/*nothing to do, just return to wake up the paushe*/
}

unsigned int sleep1(unsigned int nsecs)
{
	int jmp_rs;
	if (signal(SIGALRM, sig_alrm) == SIG_ERR) 
		return (nsecs);
	if((jmp_rs = setjmp(env_alrm)) == 0) {
		alarm(nsecs);
		pause();
	}
	printf("jmp_rs = %d\n", jmp_rs);
	return(alarm(0));
}
int main(int argc, char *argv[])
{
	printf("hello world\n");
	sleep1(2);
	printf("hello world\n");
	
	return 0;
}

