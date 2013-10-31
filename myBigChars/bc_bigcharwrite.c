#include "myBigChars.h"

int bc_bigcharwrite(int fd, int *big, int count)
{
	int err;
	
	err = write(fd, &count, sizeof(count));
	if (err == -1)
		return -1;
	err = write(fd, big, count * (sizeof(int)) * 2);
	if (err == -1)
		return -1;
	
	return 0;
}
