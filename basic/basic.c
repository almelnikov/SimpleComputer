#include "basic.h"

int val_table[26];
struct b_label labels[100];
struct memory_t memory[100];
int code_pos = 0, val_pos = 99, label_pos = 0;

int find_label(int label)
{
	int i;
	
	for (i = 0; i < label_pos; i++) {
		if (labels[i].label == label)
			return labels[i].pos;
	}
	return -1;
}

char *get_label_and_keyw(char *str, int *label, char *keyword)
{
	int cnt;
	int i = 0;
	
	cnt = sscanf(str, "%d%s", label, keyword);
	if (cnt != 2)
		return NULL;
	for (; (str[i] == ' ') || (str[i] == '\t'); i++);
	for (; (str[i] != ' ') && (str[i] != '\t'); i++);
	for (; (str[i] == ' ') || (str[i] == '\t'); i++);
	for (; (str[i] != ' ') && (str[i] != '\t'); i++);
	for (; (str[i] == ' ') || (str[i] == '\t'); i++);
	return str + i;
}

int get_keyword_code(char *str)
{
	if (strcmp(str, "REM") == 0)
		return KEYW_REM;
	else if (strcmp(str, "INPUT") == 0)
		return KEYW_INPUT;
	else if (strcmp(str, "OUTPUT") == 0)
		return KEYW_OUTPUT;
	else if (strcmp(str, "GOTO") == 0)
		return KEYW_GOTO;
	else if (strcmp(str, "IF") == 0)
		return KEYW_IF;
	else if (strcmp(str, "LET") == 0)
		return KEYW_LET;
	else if ((strcmp(str, "END") == 0) || ((strcmp(str, "END\n") == 0)
		return KEYW_END;
	else
		return -1;
}

int is_delim(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\0') || (c == '\n'))
		return 0;
	else
		return -1;
}

char *cpy_token(char *token, char *str)
{
	int i;
	
	for (i = 0; (str[i] == ' ') || (str[i] == '\t'); i++);
	str += i;
	for (i = 0; is_delim(str[i]) != 0; i++) {
		token[i] = str[i];
	}
	str[i] = '\0';
}

int srt_is_empty(char *str)
{
	int i;
	
	for (; (str[i] == ' ') || (str[i] == '\t'); i++);
	if ((str[i] == '\n') || (str[i] == '\0'))
		return 0;
	else
		return -1;
}

int test_argv(char *argv[])
{
	char *ptr1;
	
	ptr1 = strrchr(argv[1], '.');
	if ((strcmp(ptr1, ".o") != 0))
		return -1;
	else
		return 0;
}

int is_value(char *str)
{
	if ((str[0] >= 'A') && (str[0] <= 'Z')) {
		if (str[1] == '\0')
			return 0;
		else
			return -1;
	}
	else
		return -1;
}

int get_val_addr(char c)
{
	if ((c >= 'A') && (c <= 'Z')) {
		if (val_table[c-'A'] < 0) {
			val_table[c-'A'] = val_pos;
			memory[val_pos].is_val = 1;
			val_pos++;
		}
		else
			return val_table[c-'A'];
	}
	else
		return -1;
}

int parse_line(char *str, int key_w)
{
	char *ptr;
	char token[256];
	int readen, label;
	
	switch (key_w) {
		case KEYW_INPUT:
			ptr = cpy_token(token, str);
			if ((!srt_is_empty(ptr)) && (!is_value(token))) {
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 0x10; // READ
				memory[code_pos].operand = get_val_addr(token[0]);
				code_pos++;
			}
			else {
				perror("Not a valid value\n");
				exit(1);
			}
			break;
		
		case KEYW_OUTPUT:
			ptr = cpy_token(token, str);
			if ((!srt_is_empty(ptr)) && (!is_value(token))) {
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 0x11; // WRITE
				memory[code_pos].operand = get_val_addr(token[0]);
				code_pos++;
			}
			else {
				perror("Not a valid value\n");
				exit(1);
			}
			break;
		
		case KEYW_GOTO:
			readen = sscanf(str, "%d", &label);
			if (readen == 1) {
				int addr;
				
				addr = find_label(label);
				if (addr < 0) {
					perror("Label not found!\n");
					exit(1);
				}
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 0x40; // JUMP
				memory[code_pos].operand = addr;
				code_pos++;
			}
			else  {
				perror("Not a valid value\n");
				exit(1);
			}
			break;
		
		case KEYW_END:
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 0x43; // HALT
			memory[code_pos].operand = 0;
			code_pos++;
			break;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *input, *output;
	char asm_filename[256];
	char line[256], keyw_str[256];
	char *str;
	int i;
	int label, keyw;
	
	if (argc != 3) {
		perror("Incorrect arguments!\n");
		exit(1);
	}
	if (test_argv(argv) != 0) {
		perror("Incorrect arguments!\n");
		exit(1);
	}
	strcpy(asm_filename, argv[2]);
	strcat(asm_filename, ".sa");
	if ((input = fopen(argv[2], "rb")) == NULL) {
		fprintf(stderr, "Cannot open file:%s", argv[2]);
		exit(1);
	}
	if ((output = fopen(asm_filename, "wb")) == NULL) {
		fprintf(stderr, "Cannot open file:%s", asm_filename);
		exit(1);
	}
	
	for (i = 0; i < 26; i++)
		val_table[i] = -1;
	while (fgets(line, 256, input)) {
		if (srt_is_empty(line) == 0)
			continue;
		str = get_label_and_keyw(line, &label, keyw_str);
		if (str == NULL) {
			perror("Unknown operator!\n");
			exit(1);
		}
		keyw = get_keyword_code(line);
		if (keyw < 0) {
			perror("Unknown operator!\n");
			exit(1);
		}
		labels[label_pos].label = label;
		labels[label_pos].pos = code_pos;
		label_pos++;
	}

	return 0;
}