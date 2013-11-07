#include "SimpleComputer.h"

int change_acc(int pos)
{
	int plus_flag, num;

	refresh_gui(pos);
	if (scan_num(&plus_flag, &num) != 0) {
		printf("Not a number!");
		return -1;
	}
	if ((num >= 0) && (num < 0x8000)) {
		accumulator = num;
	}
	else {
		printf("Accumutalor is 15 bit wide");
		return -1;
	}
	return 0;
}