CC = gcc
CFLAGS = -g

.PHONY: clean

all:
	$(CC) $(CFLAGS) -c rk_readkey.c rk_mytermsave.c rk_mytermrestore.c rk_mytermregime.c
	ar rvs ../libs/libmyReadkey.a *.o

clean:
	rm -f *.o
