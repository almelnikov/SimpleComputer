#include "SimpleComputer.h"

void print_counter()
{
	mt_gotoXY(70, 5);
	printf("%0*X", 4, inst_counter);
}
