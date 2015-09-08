#include "../../include/parent_child_sync.h"

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int n;
	pid_t pid;
	int fd;

	if (argc != 2)
		err_sys("usage: a.out <pathname>");
	if ((fd = open(argv[1], O_RDWR)) < 0)
		err_sys("open %s file failed", argv[1]);

	memset(line, '\0', MAXLINE);
	TELL_WAIT();
	pid = fork();
	switch (pid) {
		case -1://error
			err_sys("fork error");
		case 0://child
			WAIT_PARENT();
			lseek(fd, SEEK_SET, 0);
			if ((n = read(fd, line, MAXLINE)) < 0)
				err_sys("read error form %s", argv[1]);
			printf("read %d bytes:", n);
			fflush(stdout);
			write(STDOUT_FILENO, line, n);
			TELL_PARENT(getppid());
			break;
		default://parent
			sleep(2);
			n = write(fd, "hello child\n", 13);
			printf("write %d bytes\n", n);
			fflush(stdout);
			TELL_CHILD(pid);
			WAIT_CHILD();
			break;
	}
	close(fd);
	exit(0);
}
