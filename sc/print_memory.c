#include "SimpleComputer.h"

void print_memory(int x, int y, int position)
{
	int i, j;
	int mem, command;
	int opcode, operand;

	for (i = 0; i < 10; i++) {
		mt_gotoXY(x, y + i);
		for (j = 0; j < 10; j++) {
			mem = sc_memory[i*10+j] & 0x3FFF;
			command = (sc_memory[i*10+j] >> 14) & 1;
			opcode = (mem >> 7) & 0x7F;
			operand = mem & 0x7F;
			if ((i * 10 + j) == position) {
				mt_setfgcolor(clr_black);
				mt_setbgcolor(clr_red);
			}
			if (command == 0)
				printf("+%02X%02X", opcode, operand);
			else
				printf(" %04X", mem);
			if ((i * 10 + j) == position) {
				mt_setfgcolor(clr_default);
				mt_setbgcolor(clr_default);
			}
			if (j != 9)
				printf(" ");
		}
	}
}
