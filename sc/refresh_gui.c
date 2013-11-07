#include "SimpleComputer.h"

void refresh_gui(int position)
{
	mt_clrscr();
	print_boxes();
	print_labels();
	print_keys(48, 14);
	print_counter();
	print_memory(2, 2, position);
	print_flags(68, 11);
	print_mcell(big_chars, position);
	mt_gotoXY(1, 23);
}
