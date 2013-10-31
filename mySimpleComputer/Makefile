CC = gcc
CFLAGS = -g

.PHONY: clean

all:
	$(CC) $(CFLAGS) -c int_cmp.c sc_memoryInit.c sc_memorySave.c sc_regGet.c sc_regSet.c sc_commandEncode.c sc_commandDecode.c sc_memoryGet.c sc_memoryLoad.c sc_memorySet.c sc_regInit.c vals.c
	ar rvs ../libs/libmySimpleComputer.a *.o

clean:
	rm -f *.o
