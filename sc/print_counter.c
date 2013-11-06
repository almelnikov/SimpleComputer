#include "SimpleComputer.h"

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
