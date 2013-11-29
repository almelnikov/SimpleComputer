#include "SimpleComputer.h"

int ALU(int command, int operand)
{
	int tmp;

	switch (command) {
		case 0x30: /* ADD */
			accumulator += sc_memory[operand];
			break;
			
		case 0x31: /* SUB */
			accumulator -= sc_memory[operand];
			break;
		
		case 0x32: /* MUL */
			accumulator *= sc_memory[operand];
			break;
		
		case 0x33: /* DIV */
			if (sc_memory[operand] != 0)
				accumulator /= sc_memory[operand];
			else {
				sc_regSet(FLAG_DIVISION, 1);
				return -1;
			}
			break;
	}
	if ((accumulator > 0x7FFF) || (accumulator < 0)) {
		accumulator &= 0x7FFF;
		sc_regSet(FLAG_OVERFLOW, 1);
	}
	else
		sc_regSet(FLAG_OVERFLOW, 0);
	return 0;
}
