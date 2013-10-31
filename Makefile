CC = gcc
CFLAGS = -g
LFLAGS = -L./lib/

.PHONY: clean

all:
	cd mySimpleComputer && make all
	cd myTerm && make all
	cd myBigChars && make all
	cd tests && make all

clean:
	cd mySimpleComputer && make clean
	cd myTerm && make clean
	cd myBigChars && make clean
	cd tests && make clean
	rm -f ./libs/*.a