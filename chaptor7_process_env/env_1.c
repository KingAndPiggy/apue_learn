/*
 *
 */

#include "../include/apue.h"

int main(int agrc, char *argv[])
{
	int i = 0;
	while (environ[1] != NULL) {
		printf("%s\n", environ[i++]);
	}
	printf("environ over\n");

	return 0;
}
