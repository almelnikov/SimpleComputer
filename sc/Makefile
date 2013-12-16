CC = gcc
CFLAGS = -g
INCLUDE = -I../mySimpleComputer -I../myTerm -I../myBigChars -I../myReadkey
LIBS = -L../libs
SRCS = print_keys.c print_flags.c print_memory.c print_boxes.c print_labels.c print_counter.c print_mcell.c refresh_gui.c scan_num.c change_acc.c change_cnt.c change_mcell.c memory_save.c memory_load.c print_operation.c set_signals.c timer_handler.c usrsig_handler.c CU.c ALU.c read_mcell.c main.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(INCLUDE) $(LIBS) $(CFLAGS) -o ../SimpleComputer $(SRCS) -lmySimpleComputer -lmyBigChars -lmyTerm -lmyReadkey

clean:
	rm -f ../SimpleComputer memory