#include "myBigChars.h"

int bc_getbigcharpos(int *big, int x, int y, int *value)
{
	int pos;

	if ((x < 0) || (y < 0) || (x > 7) || (y > 7))
		return -1;
	if (y <= 3)
		pos = 0;
	else
		pos = 1;
	y = y % 4;
	*value = (big[pos] >> (y*8 + x)) & 1;

	return 0;
}
