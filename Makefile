CC = gcc
CFLAGS = -g
LFLAGS = -L./lib/

.PHONY: clean

all: mySimpleComputer.a myTerm.a myBigChars.a myReadkey.a tests SimpleComputer

mySimpleComputer.a:
	cd mySimpleComputer && make all

myTerm.a:
	cd myTerm && make all
	
myBigChars.a:
	cd myBigChars && make all
	
myReadkey.a:
	cd myReadkey && make all
	
tests:
	cd tests && make all
	
SimpleComputer:
	cd sc && make all

clean:
	cd mySimpleComputer && make clean
	cd myTerm && make clean
	cd myBigChars && make clean
	cd myReadkey && make clean
	cd tests && make clean
	cd sc && make clean
	rm -f ./libs/*.a