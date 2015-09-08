/*
 *使用popen实现的分页程序
 *
 */

#include "../../include/apue.h"
#include <sys/wait.h>

#define PAGER "${PAGER:-more}"

int main(int argc, char *argv[])
{
	FILE *fpin, *fpout;
	char line[MAXLINE];

	if (argc != 2)
		err_sys("usage: a.out <pathname>");

	if ((fpin = fopen(argv[1], "r")) == NULL)
		err_sys("fopen %s file failed", argv[1]);

	if ((fpout = popen(PAGER, "w")) == NULL)
		err_sys("popen error");
	/*copy argv[1] to pager*/

	while (fgets(line, MAXLINE, fpin) != NULL) {
		if (fputs(line, fpout) == EOF)
			err_sys("fputs to fpout error");
	}

	if (ferror(fpin))
		err_sys("fgets error");

	if (pclose(fpout) == -1)
		err_sys("pclose fpout");

	exit(0);
}
