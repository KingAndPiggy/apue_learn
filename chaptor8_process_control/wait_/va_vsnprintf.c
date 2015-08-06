/*
 *可变参函数
 *
 */
#include "../../include/apue.h"
#include "../../include/pr_wait.h"
#include <stdarg.h>

void printkk(char *fmt, ...)
{
	va_list ap;
	int size = 100;
	int n;
	char  *p;

	if ((p = malloc(size)) == NULL) {
		fprintf(stderr, "malloc error.\n");
		exit(1);
	}
	va_start(ap, fmt);
	n = vsnprintf(p, size, fmt, ap);
	va_end(ap);
	printf("value of n:%d\n", n);
	printf("p:%s\n", p);
}
int main(int argc, char *argv[])
{
	printkk("%s %d %d %c %s", "hello", 10, 89, 'a', "world");
	return 0;
}
