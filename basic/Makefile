CC = gcc
CFLAGS = -g
INCLUDE = -I../mySimpleComputer
LIBS = -L../libs
SRCS = basic.c rpn.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(INCLUDE) $(LIBS) $(CFLAGS) -o ../sbasic $(SRCS) -lmySimpleComputer

clean:
	rm -f ../sbasic
	
