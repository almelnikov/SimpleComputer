#include "myTerm.h"

int mt_getscreensize(int *rows, int *cols)
{
	struct winsize w;

	if (!ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)) {
		*rows = w.ws_row;
		*cols = w.ws_col;
		return 0;
	}
	else
		return -1;
}

