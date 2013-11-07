#include "SimpleComputer.h"

int change_cnt(int pos)
{
	int plus_flag, num;

	refresh_gui(pos);
	if (scan_num(&plus_flag, &num) != 0) {
		printf("Not a number!");
		return -1;
	}
	if ((num >= 0) && (num < 0x100)) {
		inst_counter = num;
	}
	else {
		printf("Accumutalor range: from 0 to 99 (0x63)");
		return -1;
	}
	return 0;
}