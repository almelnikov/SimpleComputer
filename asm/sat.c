#include "sat.h"

int str2sc_word(char *str, int *value)
{
	int pos = 0, plus = 1;
	int n;
	int byte1, byte2;

	if (str[0] == '+') {
		plus = 0;
		pos = 1;
	}
	if (sscanf(str + pos, "%x", &n) != 1)
		return -1;
	byte1 = n & 0xFF;
	byte2 = n >> 8;
	if ((byte1 > 0x7F) || (byte2 > 0x7F))
		return -1;
	*value = byte1 | (byte2 << 7) | (plus << 14);
	return 0;
}

int str2command(char *str)
{
	int ret;

	if (strcmp(str, "READ") == 0)
		ret = 0x10;
	else if (strcmp(str, "WRITE") == 0)
		ret = 0x11;
	else if (strcmp(str, "LOAD") == 0)
		ret = 0x20;
	else if (strcmp(str, "STORE") == 0)
		ret = 0x21;
	else if (strcmp(str, "ADD") == 0)
		ret = 0x30;
	else if (strcmp(str, "SUB") == 0)
		ret = 0x31;
	else if (strcmp(str, "DIVIDE") == 0)
		ret = 0x32;
	else if (strcmp(str, "MUL") == 0)
		ret = 0x33;
	else if (strcmp(str, "JUMP") == 0)
		ret = 0x40;
	else if (strcmp(str, "JNEG") == 0)
		ret = 0x41;
	else if (strcmp(str, "JZ") == 0)
		ret = 0x42;
	else if (strcmp(str, "HALT") == 0)
		ret = 0x43;
	else if (strcmp(str, "JNP") == 0)
		ret = 0x59;
	else
		ret = -1;
	
	return ret;
}

int pars_line(char *str, int *addr, int *value)
{
	char *ptr;
	int operand, command;
	int flag_assign = 0;
	
	ptr = strchr(str, ';');
	if (ptr != NULL)
		*ptr = '\0';
	ptr = strchr(str, '\n');
	if (ptr != NULL)
		*ptr = '\0';
	ptr = strtok(str, " \t");
	if (ptr == NULL)
		return EMPTY_STR;
	if (sscanf(ptr, "%d", addr) != 1) {
		return ERR_ARG1;
	}
	if ((*addr < 0) || (*addr >= MEMSIZE))
		return ERR_ARG1;
	ptr = strtok(NULL, " \t");
	if (ptr == NULL)
		return ERR_FEW;
	else
	if (strcmp(ptr, "=") == 0)
		flag_assign = 1;
	else {
		command = str2command(ptr);
		if (command == -1)
			return ERR_ARG2;
	}
	ptr = strtok(NULL, " \t");
	if (ptr == NULL)
		return ERR_FEW;
	if (!flag_assign) {
		if (sscanf(ptr, "%d", &operand) != 1) {
			return ERR_ARG3;
		}
	}
	else {
		if (str2sc_word(ptr, value) == -1) {
			return ERR_ARG3;
		}
	}
	if ((operand < 0) || (operand >= MEMSIZE))
		return ERR_ARG3;
	ptr = strtok(NULL, " \t");
	if (ptr != NULL)
		return ERR_MANY;
	if (!flag_assign) {
		sc_commandEncode(command, operand, value);
	}
	return 0;
}

void print_error(char *line, int line_cnt, int err)
{
	switch (err) {
		case ERR_ARG1:
			fprintf(stderr, "%d: first argument isn't a number\n", line_cnt);
			break;
		
		case ERR_ARG2:
			fprintf(stderr, "%d: unknown command\n", line_cnt);
			break;
		
		case ERR_ARG3:
			fprintf(stderr, "%d: third argument isn't a number\n", line_cnt);
			break;
		
		case ERR_FEW:
			fprintf(stderr, "%d: should be three aguments\n", line_cnt);
			break;
		
		case ERR_MANY:
			fprintf(stderr, "%d: too many arguments\n", line_cnt);
			break;
	}
	fprintf(stderr, "%s", line);
}

int test_argv(char *argv[])
{
	char *ptr1, *ptr2;
	
	ptr1 = strrchr(argv[1], '.');
	ptr2 = strrchr(argv[2], '.');
	if ((strcmp(ptr1, ".o") != 0) || (strcmp(ptr2, ".sa") != 0))
		return -1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	char buf[256], line[256];
	char add_mem[MEMSIZE];
	FILE *input, *output;
	int value, addr, line_cnt = 1;
	int err;
	int flag_err = 0;
	
	if (argc != 3) {
		perror("Incorrect arguments!\n");
		exit(1);
	}
	if (test_argv(argv) != 0) {
		perror("Incorrect arguments!\n");
		exit(1);
	}
	if ((output = fopen(argv[1], "wb")) == NULL) {
		fprintf(stderr, "Cannot open file:%s", argv[1]);
		exit(1);
	}
	if ((input = fopen(argv[2], "rb")) == NULL) {
		fprintf(stderr, "Cannot open file:%s", argv[2]);
		exit(1);
	}
	
	memset(add_mem, 0, MEMSIZE);
	memset(sc_memory, 0, MEMSIZE * sizeof(int));
	while (fgets(line, 256, input)) {
		strcpy(buf, line);
		err = pars_line(buf, &addr, &value);
		if (err == 0) {
			if (add_mem[addr] == 0) {
				sc_memory[addr] = value;
			}
			else {
				fprintf(stderr, "%d: Command with %d addres already exists\n%s",  line_cnt, addr, line);
				flag_err = 1;	
			}
		}
		else if (err < 0) {
			print_error(line, line_cnt, err);
			flag_err = 1;
		}
		line_cnt++;
	}
	if (flag_err == 0) {
		fwrite(sc_memory, 1, MEMSIZE*sizeof(int), output);
	}
	fclose(input);
	fclose(output);
	return 0;
}
