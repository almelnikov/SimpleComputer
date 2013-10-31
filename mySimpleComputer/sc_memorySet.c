#include "mySimpleComputer.h"

int sc_memorySet(int address, int value)
{
	if ((address >= 0) && (address < MEMSIZE)) {
		sc_memory[address] = value;
		return 0;
	}
	else
		return ERR_WRONG_ADDR;
}
