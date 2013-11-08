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
	int exit_flag = 0, refresh_flag = 0;
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
	close(fd);
	setbuf(stdout, NULL);
	while (!exit_flag) {
		if (!refresh_flag)
			refresh_gui(position);
		rk_readkey(&key);
		switch (key) {
			case KEY_up:
				if (cursor_y != 0)
					cursor_y--;
				else
					cursor_y = 9;
				refresh_flag = 0;
				break;
			case KEY_down:
				cursor_y = (cursor_y + 1) % 10;
				refresh_flag = 0;
				break;
			case KEY_left:
				if (cursor_x != 0)
					cursor_x--;
				else
					cursor_x = 9;
				break;
				refresh_flag = 0;
			case KEY_right:
				cursor_x = (cursor_x + 1) % 10;
				refresh_flag = 0;
				break;
			case KEY_f5:
				refresh_flag = change_acc(position);
				break;
			case KEY_f6:
				refresh_flag = change_cnt(position);
				break;
			case KEY_enter:
				refresh_flag = change_mcell(position);
				break;
			case KEY_q:
				exit(0);
				break;
		}
		position = cursor_y * 10 + cursor_x;
	}
	
	return 0;
}