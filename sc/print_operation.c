#include "SimpleComputer.h"

void print_operation(int position)
{
	int command = (sc_memory[position] >> 7) & 0x7F;
	int operand = sc_memory[position] & 0x7F;
	int is_command = (sc_memory[position] >> 14) & 1;
	char c;
	
	mt_gotoXY(68, 8);
	if ((position >= 0) && (position < 100)) {
		if (is_command == 0)
			c = '+';
		else
			c = ' ';
		printf("%c%02X : %02X", c, command, operand);
	}
}