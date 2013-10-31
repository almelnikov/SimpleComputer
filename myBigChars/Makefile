CC = gcc
CFLAGS = -g
INCLUDE = -I../myTerm

.PHONY: clean

all:
	$(CC) $(INCLUDE) $(CFLAGS) -c bc_printA.c bc_box.c bc_printbigchar.c bc_setbigcharpos.c bc_getbigcharpos.c bc_bigcharwrite.c bc_bigcharread.c
	ar rvs ../libs/libmyBigChars.a *.o

clean:
	rm -f *.o
