CC = gcc
CFLAGS = -g

.PHONY: clean

all:
	gcc -g -c mt_clrscr.c mt_getscreensize.c mt_gotoXY.c mt_setbgcolor.c mt_setfgcolor.c
	ar rvs ../libs/libmyTerm.a *.o

clean:
	rm -f *.o
