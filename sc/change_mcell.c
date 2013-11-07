#include "SimpleComputer.h"

int change_mcell(int pos)
{
	int plus_flag, num;
	int command, operand, mem;

	refresh_gui(pos);
	if (scan_num(&plus_flag, &num) != 0) {
		printf("Not a number!");
		return -1;
	}
	if ((num >= 0) && (num < 0x8000)) {
		if (plus_flag) {
			if (((num >> 7) & 1) == 1) {
				printf("Wrong instruction allign");
				return -1;
			}
			command = (num >> 8) & 0x7F;
			operand = num & 0x7F;
			mem = (command << 7) | operand;
		}
		else 
			mem = (1 << 14) | num;
		if ((pos >= 0) && (pos < 100))
			sc_memorySet(pos, mem);
	}
	else {
		printf("Memory cell is 15 bit wide");
		return -1;
	}
	return 0;
}