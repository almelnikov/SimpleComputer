#include "myReadkey.h"

int rk_mytermrestore()
{
	struct termios options;
	FILE *save;

	if ((save = fopen("termsettings", "rb")) == NULL)
		return -1;
	if (fread(&options, sizeof(options), 1, save) > 0)
		if (tcgettattr(STDIN_FILENO, TCSAFLUSH, &options) != 0)
			return -1;
	else
		return -1;

	return 0;
}
