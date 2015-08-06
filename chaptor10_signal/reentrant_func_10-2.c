/*
  *use alarm and getpwnam functions.
  *Time:15-8-6
  *Author: Mr king
  */

#include "../include/apue.h"
#include <sys/types.h>
#include <pwd.h>


static void my_alarm(int signo)
{
	struct passwd *rootptr;

	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
		err_sys("getpwnam(root) error");
	alarm(1);
}

int main(int argc, char *argv[])
{
	struct passwd *ptr;

	signal(SIGALRM, my_alarm);
	alarm(1);
	while(1) {
		if((ptr = getpwnam("king")) == NULL)
			err_sys("getpwnam(king) error");
		if(strcmp(ptr->pw_name, "king") != 0)
			printf("return value corrupted pw_name = %s\n", ptr->pw_name);
	}
}
