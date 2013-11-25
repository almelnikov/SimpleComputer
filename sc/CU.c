#include "SimpleComputer.h"

void CU()
{
	int command, operand;
	
	if (inst_counter >= MEMSIZE) {
		sc_regSet(FLAG_OUTMEM, 1);
		return;
	}
	if (sc_commandDecode(sc_memory[inst_counter], &command, &operand) != 0) {
		sc_regSet(FLAG_COMMAND , 1);		
		return;
	}
}