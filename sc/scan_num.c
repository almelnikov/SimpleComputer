#include "SimpleComputer.h"

int scan_num(int *plus_flag, int *n)
{
	char buf[256];
	int pos = 0;
	
	fgets(buf, 256, stdin);
	if (buf[0] == '+') {
		pos = 1;
		*plus_flag = 1;
	}
	else
		*plus_flag = 0;
	if (sscanf(buf + pos, "%x", n) != 1)
		return -1;
	return 0;
}