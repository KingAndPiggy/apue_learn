/*
 *
 *
 */

#include "../../include/apue.h"
#include <setjmp.h>

jmp_buf jmpbuf;
void jmp_func0(void)
{
	printf("-This jmp_func0: ");
	longjmp(jmpbuf, 3);
}
void jmp_func1(void)
{
	printf("-This jmp_func0: ");
	longjmp(jmpbuf, 4);
}
void jmp_func2(void)
{
	printf("-This jmp_func2: ");
	longjmp(jmpbuf, 5);
}
void alrm_fun(int signo)
{
	printf("--alarm func---\n");
	jmp_func0();
}
int main(int argc, char *argv[])
{
	sigset_t oldmask;
	
	sigemptyset(&oldmask);
	signal(SIGALRM, alrm_fun);	
	sigprocmask(0, NULL, &oldmask);
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	switch (setjmp(jmpbuf)) {
		case 3:
			printf("return func0, call fun1\n");
		//	sigprocmask(SIG_SETMASK, &oldmask, NULL);
			jmp_func1();
			break;
		case 4:
			printf("return func1, call fun2\n");
		//	sigprocmask(SIG_SETMASK, &oldmask, NULL);
			jmp_func2();
			break;
		case 5:
			printf("return func2, break\n");
		//	sigprocmask(SIG_SETMASK, &oldmask, NULL);
			break;
	}
	printf("call alarm\n");
	alarm(2);
	sleep(2);
	printf("Done...\n");

	return 0;
}
