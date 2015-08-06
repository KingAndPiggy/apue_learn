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
	int d;
	int c, *s;

	va_start(ap, fmt);
	while (*fmt) {
		switch (*fmt++) {
			case 's':
				s = va_arg(ap, char *);
				printf("string: %s\n", s);
				break;
			case 'd':
				d = va_arg(ap, int);
				printf("int: %d\n", d);
				break;
			case 'c':
				c = (char) va_arg(ap, int);
				printf("char: %c\n", c);
				break;
		}
	}

	va_end(ap);
}
int main(int argc, char *argv[])
{
	printkk("%s %d %d %c %s", "hello", 10, 89, 'a', "world");
	return 0;
}
