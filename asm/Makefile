CC = gcc
CFLAGS = -g
INCLUDE = -I../mySimpleComputer
LIBS = -L../libs
SRCS = sat.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(INCLUDE) $(LIBS) $(CFLAGS) -o ../sat $(SRCS) -lmySimpleComputer

clean:
	rm -f ../sat
