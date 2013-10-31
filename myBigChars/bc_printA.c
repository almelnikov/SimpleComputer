#include "myBigChars.h"

int bc_printA(char *str)
{
	printf("\E(0%s\E(B", str);
	return 0;
}