#include "SimpleComputer.h"

void usrsig_handler(int sig)
{
	alarm(0);
	//sc_memoryInit();
	write_used = 0;
	sc_regInit();
	sc_regSet(FLAG_INTERRUPT, 1);
	inst_counter = 0;
	accumulator = 0;
}