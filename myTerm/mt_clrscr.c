#include "myTerm.h"

int mt_clrscr()
{
	printf("\E[H\E[2J");
	return 0;
}
