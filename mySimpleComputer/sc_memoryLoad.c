#include "mySimpleComputer.h"

int sc_memoryLoad(char *filename)
{
	FILE *save;
	int nreaden;
	int i;
	
	save = fopen(filename, "rb");
	if (save == NULL)
		return ERR_OPEN_FILE;
	nreaden = fread(sc_memory, sizeof(*sc_memory) * 100, 1, save);
	for (i = 0; i < 100; i++)
		sc_memory[i] &= 0x7FFF;
	fclose(save);
	if (nreaden != 1)
		return ERR_FILE_SIZE;
	else
		return 0;
}
