CC = gcc
CFLAGS = -g
LIBS = -L../libs/
INCLUDE = -I../myTerm -I../mySimpleComputer -I../myBigChars

.PHONY: clean

all: test_sc test_mt test1 test_bc test2

test_sc:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o test_sc test_sc.c -lmySimpleComputer

test_mt:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o test_mt test_mt.c -lmyTerm

test1:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o test1 test1.c -lmySimpleComputer -lmyTerm

test_bc:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o test_bc test_bc.c -lmyBigChars -lmyTerm
	
test2:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o test2 test2.c -lmySimpleComputer -lmyBigChars -lmyTerm

clean:
	rm -f *.o
	rm -f test_sc test_mt test1 test_bc test2
	rm -f memory bigtest bigchars
