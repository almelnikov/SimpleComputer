#include "mySimpleComputer.h"

int sc_memoryLoad(char *filename)
{
	FILE *save;
	int nreaden;
	
	save = fopen(filename, "rb");
	if (save == NULL)
		return ERR_OPEN_FILE;
	nreaden = fread(sc_memory, 1, sizeof(*sc_memory) * 100, save);
	fclose(save);
	if (nreaden != 1)
		return ERR_FILE_SIZE;
	else
		return 0;
}
