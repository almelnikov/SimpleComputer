#include "SimpleComputer.h"

void timer_handler()
{
	refresh_gui(inst_counter);
	inst_counter++;
	alarm(1);
}