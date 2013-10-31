#ifndef __GUARD_MYTERM
#define __GUARD_MYTERM

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

enum colors {
	clr_black,
	clr_red,
	clr_green,
	clr_brown,
	clr_blue,
	clr_magenta,
	clr_cyan,
	clr_light_blue,
	clr_default
};

int mt_clrscr();
int mt_gotoXY(int x, int y);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors color);
int mt_setbgcolor(enum colors color);

#endif /* __GUARD_MYTERM */
