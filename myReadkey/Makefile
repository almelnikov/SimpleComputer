CC = gcc
CFLAGS = -g
SRCS = rk_readkey.c rk_mytermsave.c rk_mytermrestore.c rk_mytermregime.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all:
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rvs ../libs/libmyReadkey.a $(OBJS)

clean:
	rm -f *.o
