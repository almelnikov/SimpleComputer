#include "SimpleComputer.h"

void CU()
{
	int command, operand;
	int flag, read_suc;
	
	if (inst_counter >= MEMSIZE) {
		sc_regSet(FLAG_OUTMEM, 1);
		sc_regSet(FLAG_INTERRUPT, 1);
		return;
	}
	if (sc_commandDecode(sc_memory[inst_counter], &command, &operand) != 0) {
		sc_regSet(FLAG_COMMAND, 1);
		sc_regSet(FLAG_INTERRUPT, 1);
		return;
	}
	if ((operand < 0) && (operand >= MEMSIZE)) {
		sc_regSet(FLAG_COMMAND, 1);
		sc_regSet(FLAG_INTERRUPT, 1);
		return;
	}
	if ((command >= 0x30) && (command <= 0x33)) {
		if (ALU(command, operand) != 0)
			sc_regSet(FLAG_INTERRUPT, 1);
	}
	else {
		switch (command) {
			case 0x10: /* READ */
				do {
					read_suc = read_mcell(operand);
				} while(read_suc != 0);
				break;
				
			case 0x11: /* WRITE */
				write_used = 1;
				write_val = sc_memory[operand];
				break;
			
			case 0x20: /* LOAD */
				accumulator = sc_memory[operand];
				break;
			
			case 0x21: /* STORE */
				sc_memory[operand] = accumulator;
				break;
			
			case 0x40: /* JUMP */
				inst_counter = operand - 1;
				break;
			
			case 0x41: /* JNEG */
				if (((accumulator >> 14) & 1) == 1)
					inst_counter = operand - 1;
				break;
				
			case 0x42: /* JZ */
				if (accumulator == 0)
					inst_counter = operand - 1;
				break;
			
			case 0x43: /* HALT */
				sc_regSet(FLAG_INTERRUPT, 1);
				break;
			
			case 0x59: /* JNP */
				sc_regGet(FLAG_ODD, &flag);
				if (flag == 1)
					inst_counter = operand - 1;
				break;
		}
	}
}