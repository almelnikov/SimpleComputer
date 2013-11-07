#include "myBigChars.h"

int bc_printA(char *str)
{
	printf("\E(0%s\E(B", str);
	//write(STDOUT_FILENO, "\033(0", 3);
	//write(STDOUT_FILENO, str, strlen(str));
	//write(STDOUT_FILENO, "\033(B", 3);
	return 0;
}