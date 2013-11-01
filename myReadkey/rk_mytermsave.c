#include "myReadkey.h"

int rk_mytermsave()
{
	struct termios options;
	FILE *save;
	
	if (tcgetattr(STDIN_FILENO, &options) != 0)
		return -1;
	if ((save = fopen("termsettings", "wb")) == NULL)
		return -1;
	fwrite(&options, sizeof(options), 1, save);
	fclose(save);
	
	return 0;
}
