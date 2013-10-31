#include "myTerm.h"

int mt_setbgcolor(enum colors color)
{
	switch (color) {
		case clr_black:
			printf("\E[40m");
			break;
		case clr_red:
			printf("\E[41m");
			break;
		case clr_green:
			printf("\E[42m");
			break;
		case clr_brown:
			printf("\E[43m");
			break;
		case clr_blue:
			printf("\E[44m");
			break;
		case clr_magenta:
			printf("\E[45m");
			break;
		case clr_cyan:
			printf("\E[46m");
			break;
		case clr_light_blue:
			printf("\E[47m");
			break;
		case clr_default:
			printf("\E[49m");
			break;
		default:
			return -1;
	}
	return 0;
}
