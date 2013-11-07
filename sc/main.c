#include "SimpleComputer.h"

int inst_counter;
int big_chars[256];

int main()
{
	int cnt;
	int fd;
	int plus_flag, num;

	sc_memoryInit();
	sc_memorySet(0, 0x4001);
	sc_memorySet(54, 0x999);
	inst_counter = 54;
	sc_regInit();
	sc_regSet(FLAG_OVERFLOW, 1);
	sc_regSet(FLAG_OUTMEM, 1);
	
	if ((fd = open("ascibig", O_RDONLY)) == -1)
		return -1;
	bc_bigcharread(fd, big_chars, 128, &cnt);
	
	refresh_gui(36);
	scan_num(&plus_flag, &num);
	printf("%d %x\n", plus_flag, num);
	close(fd);
	
	return 0;
}
