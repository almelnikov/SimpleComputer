#include "SimpleComputer.h"

int memory_save(int position)
{
	char filename[256];
	
	printf("Enter save file name: ");
	fgets(filename, 256, stdin);
	filename[strlen(filename) - 1] = '\0';
	if (sc_memorySave(filename) == 0) {
		refresh_gui(position);
		printf("File successfully saved");
		return 0;
	}
	else {
		printf("Cannot save file: %s", filename);
		return -1;
	}
}