/*
*测量一个文件的长度
*
*/

#include "../../include/apue.h"

int main(int argc, char *argv[])
{
	int fd;
	long FileLenth;


	if(argc != 2) {
		err_sys("Error argument, Usage:./* filename");
	}
	
	fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		fprintf(stderr, "open %s file failed\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FileLenth = lseek(fd, 0, SEEK_END);
	
	printf("Data of %s: %ld\n", argv[1], FileLenth);

	close(fd);
	return 0;
}
