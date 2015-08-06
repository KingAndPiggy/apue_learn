/*
*使用read
*反序显示一个文件
*/

#include "../../include/apue.h"

int main(int argc, char *argv[])
{
	int fd; 
	char ch;
	long file_lenth;

	if(argc != 2) {
		err_sys("Error argumet, Usage:./* finename");
	}

	fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		fprintf(stderr, "file %s exists\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file_lenth = lseek(fd, 0, SEEK_END);
	printf("Data of %s:%ld\n", argv[1], file_lenth);
	lseek(fd, 0, SEEK_SET);
	while(1){
		pread(fd, &ch, 1, --file_lenth);
		if(file_lenth < 0) break;
		printf("%c\n", ch);
	}

	close(fd);

	exit(EXIT_SUCCESS);
}
