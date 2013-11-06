#include "SimpleComputer.h"

int inst_counter;

int main()
{
	int big[256];
	int cnt;
	int fd;

	sc_memoryInit();
	sc_memorySet(0, 0x4001);
	sc_memorySet(54, 0x999);
	inst_counter = 54;
	sc_regInit();
	sc_regSet(FLAG_OVERFLOW, 1);
	sc_regSet(FLAG_OUTMEM, 1);
	
	if ((fd = open("ascibig", O_RDONLY)) == -1)
		return -1;
	bc_bigcharread(fd, big, 128, &cnt);
	
	mt_clrscr();
	print_boxes();
	print_labels();
	print_keys(48, 14);
	print_counter();
	print_memory(2, 2);
	print_flags(68, 11);
	print_mcell(big);
	
	mt_gotoXY(1, 23);
	close(fd);
	
	return 0;
}
