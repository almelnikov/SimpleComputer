#include "SimpleComputer.h"

void usrsig_handler(int sig)
{
	alarm(0);
	sc_memoryInit();
	sc_regInit();
	sc_regSet(FLAG_INTERRUPT, 1);
	inst_counter = 0;
	accumulator = 0;
}