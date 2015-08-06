/*
 *
 *
 */

#include "../include/apue.h"

void my_func1(void)
{
	printf("hello world\n");
}
void my_func2(void)
{
	printf("wang hui\n");
}
int main(int argc, char *argv[])
{
	if (atexit(my_func1) != 0) 
		err_sys("Error:can't register my_func1");
	printf("%d\n", __LINE__);
	if (atexit(my_func2) != 0) 
		err_sys("Error:can't register my_func2");
	printf("%d\n", __LINE__);

	exit(1);	
}
