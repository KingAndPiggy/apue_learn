all:a.out
#complit
CC=gcc
#cflag
CFLAGS= -Wall 
#include
INCLUDE=../include
#
FILE=Template

a.out:$(FILE).o
	$(CC) $(CFLAGS) -I$(INCLUDE) $? -o $@
$(FILE).o:$(FILE).c
	$(CC) $(CFLAGS) -I$(INCLUDE) $? -c
clean:
	rm $(FILE).o 
