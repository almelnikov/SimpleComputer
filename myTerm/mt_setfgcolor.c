#include "myTerm.h"

int mt_setfgcolor(enum colors color)
{
	switch (color) {
		case clr_black:
			printf("\E[30m");
			break;
		case clr_red:
			printf("\E[31m");
			break;
		case clr_green:
			printf("\E[32m");
			break;
		case clr_brown:
			printf("\E[33m");
			break;	
		case clr_blue:
			printf("\E[34m");
			break;
		case clr_magenta:
			printf("\E[35m");
			break;
		case clr_cyan:
			printf("\E[36m");
			break;
		case clr_light_blue:
			printf("\E[37m");
			break;
		case clr_default:
			printf("\E[39m");
			break;
		default:
			return -1;
	}
	return 0;
}
