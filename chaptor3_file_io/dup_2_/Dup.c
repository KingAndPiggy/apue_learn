/*
*使用dup函数,重定向printf输出
*
*/

#include "../../include/apue.h"

int main(int argc, char *argv[])
{
	int fd;
	int fd1;

	if(argc != 2) {
		err_sys("Error argument, Usage:./* filename");
	}

	write(STDOUT_FILENO, "Now close STDOUT\n", 17);
	fflush(stdout);
	fd = open(argv[1], O_RDWR);
	/*未关闭标准输出，将显示在屏幕上*/
	printf("fd = %d,line = %d\n", fd, __LINE__);
	fflush(stdout);
	close(STDOUT_FILENO);
	/*关闭标准输出不会显示下一句*/
	printf("fd = %d,line = %d\n", fd, __LINE__);
	fflush(stdout);
	/*将fd1 -> fd 将 fd1指向fd指向的文件, 由于关闭了文件描述符1 
	  所以dup()将返回1,也就将欺骗printf等函数将标准输出指向fd*/
	fd1 = dup(fd);
	/*标准输出重定向到fd*/
	printf("fd = %d,line = %d\n", fd1, __LINE__);
	fflush(stdout);

	close(fd1);

	return 0;
}
