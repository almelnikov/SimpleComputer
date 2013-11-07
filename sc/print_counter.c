#include "SimpleComputer.h"

void print_counter()
{
	mt_gotoXY(70, 5);
	printf("%04X",  inst_counter);
}
