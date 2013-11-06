#include "SimpleComputer.h"

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
