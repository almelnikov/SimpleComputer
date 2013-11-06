#include "SimpleComputer.h"

void refresh_gui(int *big)
{
	mt_clrscr();
	print_boxes();
	print_labels();
	print_keys(48, 14);
	print_counter();
	print_memory(2, 2);
	print_flags(68, 11);
	print_mcell(big);
	mt_gotoXY(1, 23);
}
