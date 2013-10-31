#include "myBigChars.h"

int bc_printbigchar(int *big, int x, int y, enum colors fg, enum colors bg)
{
	int maxx, maxy;
	int pos, bit;
	int i, j;
	char row[9];
	
	mt_getscreensize(&maxy, &maxx);
	if ((x < 0) || (y < 0) || (x + 8 > maxx) || (y + 8 > maxy))
		return -1;
	row[8] = '\0';
	mt_setfgcolor(fg);
	mt_setbgcolor(bg);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			pos = i >> 2;
			bit = (big[pos] >> ((i % 4) * 8 + j)) & 1;
			if (bit == 0)
				row[j] = ' ';
			else
				row[j] = BOXCHAR_REC;
		}
		mt_gotoXY(x, y + i);
		bc_printA(row);
	}
	mt_setfgcolor(clr_default);
	mt_setbgcolor(clr_default);
	return 0;
}
