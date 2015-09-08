/*
 *用popen  pclose 构造一个简单的输入过滤程序，此为过滤程序
 */

#include "../../include/apue.h"
#include <ctype.h>

int main(void)
{
	int c;

	while((c = getchar()) != EOF) {
		if (isupper(c)) //判断是否为大写字母，yes return 1 no 0
			c = tolower(c);
		if (putchar(c) == EOF)
			err_sys("putchar error");

		if (c == '\n')
			fflush(stdout);
	}

	return 0;
}
