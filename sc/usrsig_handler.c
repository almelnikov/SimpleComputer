#include "SimpleComputer.h"

void usrsig_handler()
{
	sc_memoryInit();
	sc_regInit();
	inst_counter = 0;
	accumulator = 0;
}