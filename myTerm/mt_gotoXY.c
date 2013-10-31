#include "myTerm.h"

int mt_gotoXY(int x, int y)
{
	int rows, cols;

	mt_getscreensize(&rows, &cols);
	if ((y < rows) && (x < cols) && (x >= 0) && (y >= 0)) {
		printf("\E[%d;%dH", y, x);
		return 0;
	}
	else
		return -1;
}
