#include "SimpleComputer.h"

int print_mcell(int *bigchars, int pos)
{
	int command = (sc_memory[pos] >> 14) & 1;
	int mem = sc_memory[pos] & 0x3FFF;
	int i, opcode, operand;
	char str[10];
	char c;
	
	opcode = (mem >> 7) & 0x7F;
	operand = mem & 0x7F;
	if (command == 0)
		sprintf(str, "+%02X%02X", opcode, operand);
	else
		sprintf(str, " %04X", mem);
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
