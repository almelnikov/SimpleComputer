#include "SimpleComputer.h"

int memory_load(int position)
{
	char filename[256];
	
	printf("Enter save file name: ");
	fgets(filename, 256, stdin);
	filename[strlen(filename) - 1] = '\0';
	if (sc_memoryLoad(filename) == 0) {
		refresh_gui(position);
		printf("File successfully loaded");
		return 0;
	}
	else {
		printf("Cannot load file: %s", filename);
		return -1;
	}
}