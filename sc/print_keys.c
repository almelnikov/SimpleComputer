#include "SimpleComputer.h"

void print_keys(int x, int y)
{
	mt_gotoXY(x, y);
	printf("l  - load");
	mt_gotoXY(x, y + 1);
	printf("s  - save");
	mt_gotoXY(x, y + 2);
	printf("r  - run");
	mt_gotoXY(x, y + 3);
	printf("t  - step");
	mt_gotoXY(x, y + 4);
	printf("i  - reset");
	mt_gotoXY(x, y + 5);
	printf("F5 - accumulator");
    mt_gotoXY(x, y + 6);
	printf("F6 - instructionCounter");
}
