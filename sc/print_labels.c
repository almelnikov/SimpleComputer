#include "SimpleComputer.h"

void print_labels()
{
	mt_gotoXY(30, 1);
	printf(" Memory ");
	mt_gotoXY(66, 1);
	printf(" accumulator ");
	mt_gotoXY(63, 4);
	printf(" instuctionCounter ");
	mt_gotoXY(68, 7);
	printf(" Operation ");
	mt_gotoXY(68, 10);
	printf(" Flags ");
	mt_gotoXY(48, 13);
	printf(" Keys: ");
}

