#include "SimpleComputer.h"

void timer_handler(int sig)
{
	refresh_gui(inst_counter);
	CU();
	inst_counter++;
	if (!BIT_CHECK(sc_reg_flags, FLAG_INTERRUPT))
		alarm(1);
}
