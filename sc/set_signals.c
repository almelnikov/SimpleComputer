#include "SimpleComputer.h"

void set_signals()
{
	signal(SIGALRM, timer_handler);
	signal(SIGUSR1, usrsig_handler);
}