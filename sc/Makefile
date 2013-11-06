CC = gcc
CFLAGS = -g
INCLUDE = -I../mySimpleComputer -I../myTerm -I../myBigChars -I../myReadkey
LIBS = -L../libs
SRCS = print_keys.c print_flags.c print_memory.c print_boxes.c print_labels.c print_counter.c print_mcell.c main.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(INCLUDE) $(LIBS) $(CFLAGS) -o ../SimpleComputer $(SRCS) -lmySimpleComputer -lmyBigChars -lmyTerm -lmyReadkey

clean:
	rm -f ../SimpleComputer
