#include "myBigChars.h"

int bc_box(int x1, int y1, int x2, int y2)
{
	int tmp;
	int maxx, maxy;
	int i, j;
	
	if (x1 > x2) {
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	if (y1 > y2) {
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	mt_getscreensize(&maxy, &maxx);
	if ((x1 < 0) || (y1 < 0) || (x2 > maxx) || (y2 > maxy) || (x2 - x1 < 2) ||
	   (y2 - y1 < 2))
		return -1;
	mt_gotoXY(x1, y1);
	bc_printA(BOXCHAR_TL);
	for (i = x1 + 1; i < x2; i++)
		bc_printA(BOXCHAR_HOR);
	bc_printA(BOXCHAR_TR);
	for (i = y1 +1; i < y2; i++) {
		mt_gotoXY(x1, i);
		bc_printA(BOXCHAR_VERT);
		mt_gotoXY(x2, i);
		bc_printA(BOXCHAR_VERT);
	}
	mt_gotoXY(x1, y2);
	bc_printA(BOXCHAR_BL);
	for (i = x1 + 1; i < x2; i++)
		bc_printA(BOXCHAR_HOR);
	bc_printA(BOXCHAR_BR);
	return 0;
}