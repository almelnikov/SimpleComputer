CC = gcc
CFLAGS = -g
INCLUDE = -I../myTerm
SRCS = bc_printA.c bc_box.c bc_printbigchar.c bc_setbigcharpos.c bc_getbigcharpos.c bc_bigcharwrite.c bc_bigcharread.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(INCLUDE) $(CFLAGS) -c $(SRCS)
	ar rvs ../libs/libmyBigChars.a $(OBJS)

clean:
	rm -f *.o
