#include <sys/types.h>
#include <fcntl.h>
#include "myTerm.h"
#include "myBigChars.h"
#include "mySimpleComputer.h"

int inst_counter;

void print_keys(int x, int y)
{
	mt_gotoXY(x, y);
	printf("l  - load");
	mt_gotoXY(x, y + 1);
	printf("s  - save");
	mt_gotoXY(x, y + 2);
	printf("r  - run");
	mt_gotoXY(x, y + 3);
	printf("t  - step");
	mt_gotoXY(x, y + 4);
	printf("i  - reset");
	mt_gotoXY(x, y + 5);
	printf("F5 - accumulator");
    mt_gotoXY(x, y + 6);
	printf("F6 - instructionCounter");
}

void print_flags(int x, int y)
{
	mt_gotoXY(x, y);
	if (BIT_CHECK(sc_reg_flags, FLAG_OVERFLOW) == 1)
		printf("O");
	else
		printf(" ");
	if (BIT_CHECK(sc_reg_flags, FLAG_COMMAND) == 1)
		printf("E");
	else
		printf(" ");
	if (BIT_CHECK(sc_reg_flags, FLAG_INTERRUPT) == 1)
		printf("V");
	else
		printf(" ");
	if (BIT_CHECK(sc_reg_flags, FLAG_OUTMEM) == 1)
		printf("M");
	else
		printf(" ");
	if (BIT_CHECK(sc_reg_flags, FLAG_DIVISION) == 1)
		printf("Z");
	else
		printf(" ");
}

void print_memory(int x, int y)
{
	int i, j;
	int mem, command;

	for (i = 0; i < 10; i++) {
		mt_gotoXY(x, y + i);
		for (j = 0; j < 9; j++) {
			mem = sc_memory[i*10+j] & 0x3FFF;
			command = (sc_memory[i*10+j] >> 14) & 1;
			if (command == 0)
				printf("+");
			else
				printf(" ");
			printf("%0*X ", 4, mem);
		}
		mem = sc_memory[i*10+j] & 0x3FFF;
		command = (sc_memory[i*10+j] >> 14) & 1;
		if (command == 0)
			printf("+");
		else
			printf(" ");
		printf("%0*X", 4, mem);
	}
}

void print_boxes()
{
	bc_box(1, 1, 61, 12);
	bc_box(62, 1, 82, 3);
	bc_box(62, 4, 82, 6);
	bc_box(62, 7, 82, 9);
	bc_box(62, 10, 82, 12);
	bc_box(1, 13, 46, 22);
	bc_box(47, 13, 82, 22);
}

void print_labels()
{
	mt_gotoXY(30, 1);
	printf(" Memory ");
	mt_gotoXY(66, 1);
	printf(" accumulator ");
	mt_gotoXY(63, 4);
	printf(" instuctionCounter ");
	mt_gotoXY(68, 7);
	printf(" Operation ");
	mt_gotoXY(68, 10);
	printf(" Flags ");
	mt_gotoXY(48, 13);
	printf(" Keys: ");
}

void print_counter()
{
	int command = (sc_memory[inst_counter] >> 14) & 1;
	int mem = sc_memory[inst_counter] & 0x3FFF;

	mt_gotoXY(69, 5);
	if (command == 0)
		printf("+");
	else
		printf("-");
	printf("%0*X", 4, mem);
}

int print_mcell(int *bigchars)
{
	int command = (sc_memory[inst_counter] >> 14) & 1;
	int mem = sc_memory[inst_counter] & 0x3FFF;
	int i;
	char str[10];
	char c;
	
	if (command == 0)
		c = '+';
	else
		c = ' ';
	sprintf(str, "%c%0*X", c, 4, mem);
	for (i = 0; i < 5; i++) {
		mt_gotoXY(2 + 9 * i, 14);
		if (str[i] < 128)
			bc_printbigchar(bigchars + (str[i] * 2), 2 + i*9, 14, clr_default,
							clr_default);
		else
			return -1;
	}
	
	return 0;
}

int main()
{
	int big[256];
	int cnt;
	int fd;

	sc_memoryInit();
	sc_memorySet(0, 0x4001);
	sc_memorySet(54, 0x999);
	inst_counter = 54;
	sc_regInit();
	sc_regSet(FLAG_OVERFLOW, 1);
	sc_regSet(FLAG_OUTMEM, 1);
	
	if ((fd = open("ascibig", O_RDONLY)) == -1)
		return -1;
	bc_bigcharread(fd, big, 128, &cnt);
	
	mt_clrscr();
	print_boxes();
	print_labels();
	print_keys(48, 14);
	print_counter();
	print_memory(2, 2);
	print_flags(68, 11);
	print_mcell(big);
	
	mt_gotoXY(1, 23);
	close(fd);
	
	return 0;
}