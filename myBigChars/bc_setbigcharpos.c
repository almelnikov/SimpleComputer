#include "myBigChars.h"

int bc_setbigcharpos(int *big, int x, int y, int value)
{
	int pos;

	if ((x < 0) || (y < 0) || (x > 7) || (y > 7) || (value < 0) || (value > 1))
		return -1;
	if (y <= 3)
		pos = 0;
	else
		pos = 1;
	y = y % 4;
	if (value == 0)
		big[pos] &= ~(1 << (y*8 + x));
	else
		big[pos] |= 1 << (y*8 + x);
	
	return 0;
}