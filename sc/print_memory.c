#include "SimpleComputer.h"

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
