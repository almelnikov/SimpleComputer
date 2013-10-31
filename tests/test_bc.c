#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include "myBigChars.h"

/*
char bigchar_0[64] = {
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0
};
*/

char bigchar_plus[64] = {
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 1, 1, 1, 1, 1, 1, 0,
	 0, 1, 1, 1, 1, 1, 1, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0
};


char bigchar_0[64] = {
	 0, 0, 1, 1, 1, 1, 0, 0,
	 0, 1, 0, 0, 0, 0, 1, 0,
	 1, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 1,
	 0, 1, 0, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 0, 0
};

char bigchar_1[64] = {
	 0, 0, 0, 0, 0, 1, 1, 0,
	 0, 0, 0, 0, 1, 0, 1, 0,
	 0, 0, 0, 1, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0
};

char bigchar_2[64] = {
	 0, 0, 0, 1, 1, 1, 0, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 1, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 1, 0, 0,
	 0, 0, 0, 0, 1, 0, 0, 0,
	 0, 0, 0, 1, 0, 0, 0, 0,
	 0, 0, 1, 0, 0, 0, 0, 0,
	 0, 1, 1, 1, 1, 1, 1, 0
};

char bigchar_3[64] = {
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 1, 1, 1, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0
};

char bigchar_4[64] = {
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0
};

char bigchar_5[64] = {
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 1, 0, 0, 0, 0, 0,
	 0, 0, 1, 0, 0, 0, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0
};

char bigchar_6[64] = {
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 1, 0, 0, 0, 0, 0,
	 0, 0, 1, 0, 0, 0, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0
};

char bigchar_7[64] = {
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0
};

char bigchar_8[64] = {
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0
};

char bigchar_9[64] = {
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 0, 0, 0, 0, 1, 0,
	 0, 0, 1, 1, 1, 1, 1, 0
};

int arr_to_big(int *big, char *arr)
{
	int i;
	int x, y;
	
	for (i = 0; i < 64; i++) {
		x = i % 8;
		y = i / 8;
		bc_setbigcharpos(big, x, y, arr[i]);
	}
	return 0;
}

int main()
{
	int big[2], one[2], big_read[2];
	int test_buf[100];
	int big_asci[256];
	int val1, val2;
	int ret1, ret2;
	int readen;
	int fd, out_asci;
	
	mt_clrscr();
	arr_to_big(big, bigchar_0);
	arr_to_big(one, bigchar_1);
	bc_box(2, 2, 78, 20);
	bc_printbigchar(big, 4, 4, clr_black, clr_red);
	bc_printbigchar(one, 4, 12, clr_default, clr_default);
	bc_getbigcharpos(big, 3, 3, &val1);
	bc_getbigcharpos(big, 6, 1, &val2);
	mt_gotoXY(0, 21);
	printf("bc_getbigcharpos (3,3) 0?%d (6, 1) 1?%d\n", val1, val2);
	
	if ((fd = open("bigtest", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR )) == -1) {
		perror("Open error\n");
		return -1;
	}
	if (bc_bigcharwrite(fd, big, 1) != 0) {
		perror("bc_bigcharwrite error!\n");
		return -1;
	}
	lseek(fd, 0, SEEK_SET);
	if (bc_bigcharread(fd, big_read, 1, &readen) != 0) {
		perror("bc_bigcharwrite error!\n");
		return -1;
	}
	if ((big[0] != big_read[0]) || (big[1] != big_read[1])) {
		perror("big != big_read\n");
		return -1;
	}
	else
		printf("big == big_read\n");
	
	/* Init of bigchars array */
	memset(big_asci, 0, sizeof(int) * 256);
	arr_to_big(big_asci + ('+' * 2), bigchar_plus);
	arr_to_big(big_asci + ('0' * 2), bigchar_0);
	arr_to_big(big_asci + ('1' * 2), bigchar_1);
	arr_to_big(big_asci + ('2' * 2), bigchar_2);
	arr_to_big(big_asci + ('3' * 2), bigchar_3);
	arr_to_big(big_asci + ('4' * 2), bigchar_4);
	arr_to_big(big_asci + ('5' * 2), bigchar_5);
	arr_to_big(big_asci + ('6' * 2), bigchar_6);
	arr_to_big(big_asci + ('7' * 2), bigchar_7);
	arr_to_big(big_asci + ('8' * 2), bigchar_8);
	arr_to_big(big_asci + ('9' * 2), bigchar_9);
	if ((out_asci = open("bigchars", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR )) 
	   == -1) {
		perror("Open error\n");
		return -1;
	}
	if (bc_bigcharwrite(out_asci, big_asci, 128) != 0) {
		perror("bc_bigcharwrite error!\n");
		return -1;
	}
	
	/* Incorrect arguments */
	ret1 = bc_box(-1, 1, 8, 8);
	ret2 = bc_box(1, 10000, 10, 10);
	printf("bc_box returned 1:%d 2:%d\n", ret1, ret2);
	ret1 = bc_printbigchar(big, 20000, 4, clr_red, clr_green);
	ret2 = bc_setbigcharpos(big, 10, 3, 1);
	printf("bc_printbigchar returned %d bc_setbigcharpos returned %d\n", ret1, ret2);
	ret1 = bc_getbigcharpos(big, 3, 10, &val1);
	printf("bc_getbigcharpos returned %d\n", ret1);
	ret1 = bc_bigcharread(fd, test_buf, 8, &val2);
	ret2 = bc_bigcharwrite(-1, big, 1);
	printf("bc_bigcharread returned %d bc_bigcharwrite returned %d\n", ret1, ret2);
	
	close(fd);
	close(out_asci);
	
	return 0;
}