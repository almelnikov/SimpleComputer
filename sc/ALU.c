#include "SimpleComputer.h"

int ALU(int command, int operand)
{
	int tmp;

	switch (command) {
		case 0x30: /* ADD */
			accumulator += sc_memory[operand];
			break;
			
		case 0x31: /* SUB */
			if (((sc_memory[operand] >> 14) & 1) == 1)
				tmp = sc_memory[operand] | (~0x7FFF);
			else
				tmp = sc_memory[operand];
			accumulator -= tmp;
			if ((accumulator > ((int)(~0x7FFF))) && (accumulator <= 0x7FFF)) {
				accumulator &= 0x7FFF;
			}
			break;
		
		case 0x33: /* MUL */
			accumulator *= sc_memory[operand];
			break;
		
		case 0x32: /* DIV */
			if (sc_memory[operand] != 0)
				accumulator /= sc_memory[operand];
			else {
				sc_regSet(FLAG_DIVISION, 1);
				return -1;
			}
			break;
	}
	if ((accumulator & 1) == 0)
		sc_regSet(FLAG_ODD, 0);
	else
		sc_regSet(FLAG_ODD, 1);
	if ((accumulator > 0x7FFF) || (accumulator < 0)) {
		accumulator &= 0x7FFF;
		sc_regSet(FLAG_OVERFLOW, 1);
	}
	else
		sc_regSet(FLAG_OVERFLOW, 0);
	sc_regSet(FLAG_ODD, accumulator & 1);
	return 0;
}
