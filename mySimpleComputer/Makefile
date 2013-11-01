CC = gcc
CFLAGS = -g
SRCS = int_cmp.c sc_memoryInit.c sc_memorySave.c sc_regGet.c sc_regSet.c sc_commandEncode.c sc_commandDecode.c sc_memoryGet.c sc_memoryLoad.c sc_memorySet.c sc_regInit.c vals.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rvs ../libs/libmySimpleComputer.a $(OBJS)

clean:
	rm -f *.o
