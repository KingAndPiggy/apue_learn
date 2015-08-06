/*
 *
 */

#include "../include/apue.h"
#include <setjmp.h>

jmp_buf ENV_;
void test(int x)
{
	longjmp(ENV_, x);	
}
int main(int agrc, char *argv[])
{
	int i;
	int j = 1;
	if ((i = setjmp(ENV_)) != 0) {
		printf("error:%d\n", i);
	}

	printf("test begainning\n");
	if (j < 10) {
		sleep(1);
		test(j++);
	}
	printf("test over\n");

	return 0;
}
