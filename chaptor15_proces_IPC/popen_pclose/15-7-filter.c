/*
 *使用popen pclose 管道 演示过滤程序， 此为主程序
 */

#include "../../include/apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	FILE *fpin;

	memset(line, '\0', MAXLINE);

	if ((fpin = popen("./15-6-filter", "r")) == NULL)
		err_sys("popen error for: %s", "15-6-filter");

	for( ; ;) {
		fputs("prompt>", stdout);
		fflush(stdout);
		if (fgets(line, MAXLINE, fpin) == NULL)
			break;
		if (fputs(line, stdout) == EOF)
			err_sys("fputs error");
	}

	if (pclose(fpin) == -1)
		err_sys("close fpin error");

	putchar('\n');
	exit(0);
}
