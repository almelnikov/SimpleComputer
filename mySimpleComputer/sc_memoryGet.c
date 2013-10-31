#include "mySimpleComputer.h"

int sc_memoryGet(int address, int *value)
{
	if ((address >= 0) && (address < MEMSIZE)) {
		*value = sc_memory[address];
		return 0;
	}
	else
		return ERR_WRONG_ADDR;
}
