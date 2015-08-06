/*
 *
 *
 */
#include "../../include/apue.h"

int main(int argc, char *argv[])
{
	int status;

	if ((status = system("date")) < 0) {
		err_sys("system() error");
	}
	pr_wait(status);
	if ((status = system("nosuchcommond")) < 0) {
		err_sys("system() error");
	}
	pr_wait(status);
	if ((status = system("who; exit 44")) < 0) {
		err_sys("system() error");
	}
	pr_wait(status);

	exit(0);
}
