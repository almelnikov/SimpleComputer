#include "myTerm.h"

int main()
{
	int cols, rows;

	printf("This text should be cleared.\n");
	mt_clrscr();
	mt_gotoXY(0, 20);
	printf("This is 5,20");
	mt_gotoXY(0, 0);
	mt_getscreensize(&cols, &rows);
	printf("Columns: %d Rows: %d ", cols, rows);
	mt_setfgcolor(clr_red);
	printf("red text");
	mt_gotoXY(10, 10);
	mt_setfgcolor(clr_green);
	mt_setbgcolor(clr_magenta);
	printf("green on magenta");
	mt_setfgcolor(clr_default);
	mt_setbgcolor(clr_default);
	if (mt_gotoXY(20000, 1) != -1)
		printf("mt_gotoXY error\n");
	if (mt_setfgcolor(100) != -1)
		printf("mt_setfgcolor error\n");
	if (mt_setbgcolor(100) != -1)
		printf("mt_setfgcolor error\n");
	
	return 0;
}