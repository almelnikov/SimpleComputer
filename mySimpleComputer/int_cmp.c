#include "mySimpleComputer.h"


int int_cmp(const void *a, const void *b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else
	if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}
