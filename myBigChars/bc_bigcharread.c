#include "myBigChars.h"

int bc_bigcharread(int fd, int *big, int need_count, int *count)
{
	int n, cnt, err;
	
	err = read(fd, &n, sizeof(n));
	if (err == -1 || (err != sizeof(n)))
		return -1;
	cnt = read(fd, big, need_count * sizeof(int) * 2);
	if (cnt == -1)
		return -1;
	*count = cnt / (sizeof(int) * 2);
	
	return 0;
}
