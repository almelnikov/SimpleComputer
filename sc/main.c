#include "SimpleComputer.h"

int inst_counter;
int accumulator;
int big_chars[256];

int main()
{
	int cnt;
	int fd;
	int plus_flag, num;
	int cursor_x = 0;
	int cursor_y = 0;
	int position = 0;
	int exit_flag = 0;
	enum keys key;

	sc_memoryInit();
	sc_regInit();
	/*
	sc_memorySet(0, 0x4001);
	sc_memorySet(54, 0x999);
	inst_counter = 54;
	sc_regSet(FLAG_OVERFLOW, 1);
	sc_regSet(FLAG_OUTMEM, 1);
	*/
	if ((fd = open("ascibig", O_RDONLY)) == -1) {
		perror("Cannot open ascibig\n");
		return -1;
	}
	bc_bigcharread(fd, big_chars, 128, &cnt);
	while (!exit_flag) {
		refresh_gui(position);
		rk_readkey(&key);
		switch (key) {
			case KEY_up:
				if (cursor_y != 0)
					cursor_y--;
				else
					cursor_y = 9;
				break;
			case KEY_down:
				cursor_y = (cursor_y + 1) % 10;
				break;
			case KEY_left:
				if (cursor_x != 0)
					cursor_x--;
				else
					cursor_x = 9;
				break;
			case KEY_right:
				cursor_x = (cursor_x + 1) % 10;
				break;
			case KEY_f5:
				change_acc(position);
				break;
			case KEY_f6:
				change_cnt(position);
				break;
			case KEY_q:
				exit(0);
				break;
		}
		position = cursor_y * 10 + cursor_x;
	}
	/*
	scan_num(&plus_flag, &num);
	printf("%d %x\n", plus_flag, num);
	*/
	close(fd);
	
	return 0;
}
