CC = gcc
CFLAGS = -g
SRCS = mt_clrscr.c mt_getscreensize.c mt_gotoXY.c mt_setbgcolor.c mt_setfgcolor.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rvs ../libs/libmyTerm.a $(OBJS)

clean:
	rm -f *.o
