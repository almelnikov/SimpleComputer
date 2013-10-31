#include "myTerm.h"
#include "mySimpleComputer.h"

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
			mem = sc_memory[i*10+j] & 0x3FF;
			command = (sc_memory[i*10+j] >> 14) & 1;
			if (command == 0)
				printf("+");
			else
				printf(" ");
			printf("%0*X ", 4, mem);
		}
		mem = sc_memory[i*10+j] & 0x3FF;
		command = (sc_memory[i*10+j] >> 14) & 1;
		if (command == 0)
			printf("+");
		else
			printf(" ");
		printf("%0*X", 4, mem);
	}
}

int main()
{
	sc_memoryInit();
	sc_memorySet(0, 0x4001);
	sc_memorySet(54, 0x999);
	sc_regInit();
	sc_regSet(FLAG_OVERFLOW, 1);
	sc_regSet(FLAG_OUTMEM, 1);
	
	mt_clrscr();
	print_memory(2, 2);
	print_keys(46, 14);
	print_flags(68, 11);
	return 0;
}