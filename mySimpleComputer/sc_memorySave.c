#include "mySimpleComputer.h"

int sc_memorySave(char *filename)
{
	FILE *save;
	int nwritten;
	
	save = fopen(filename, "wb");
	if (save == NULL)
		return ERR_OPEN_FILE;
	nwritten = fwrite(sc_memory, sizeof(*sc_memory) * 100, 1, save);
	fclose(save);
	if (nwritten != 1)
		return ERR_FILE_SIZE;
	else
		return 0;
}
