#include "myReadkey.h"

void print_key(enum keys key)
{
	switch (key) {
		case KEY_l:
			printf("l\n");
			break;
		case KEY_s:
			printf("s\n");
			break;
		case KEY_r:
			printf("r\n");
			break;
		case KEY_t:
			printf("t\n");
			break;
		case KEY_i:
			printf("i\n");
			break;
		case KEY_q:
			printf("q\n");
			break;
		case KEY_up:
			printf("up\n");
			break;
		case KEY_down:
			printf("down\n");
			break;
		case KEY_left:
			printf("left\n");
			break;
		case KEY_right:
			printf("right\n");
			break;
		case KEY_f5:
			printf("F5\n");
			break;
		case KEY_f6:
			printf("F6\n");
			break;
	}
}

int main()
{
	struct termios options;
	enum keys key;
	char buf[100];
	
	rk_mytermsave();
	rk_mytermregime(0, 0, 1, 0, 1);
	printf("ECHO disabled\n");
	read(STDIN_FILENO, &buf, 10);
	rk_mytermrestore();
	printf("Terminal settings restored\n");
	read(STDIN_FILENO, &buf, 10);
	if (rk_mytermregime(0, 0, 0, 0, 2) == -1)
		printf("rk_mytermregime returned -1\n");
	else
		printf("Wrong rk_mytermregime return value\n");
	do {
		rk_readkey(&key);
		print_key(key);
	} while (key != KEY_q);
	
	return 0;
}