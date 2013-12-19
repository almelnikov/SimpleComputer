#include "basic.h"

int val_table[26];
struct b_label lables[100];

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
	else if (strcmp(str, "END") == 0)
		return KEYW_END;
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

int main(int argc, char *argv[])
{
	FILE *input, *output;

	if (argc != 3) {
		perror("Incorrect arguments!\n");
		exit(1);
	}
	if (test_argv(argv) != 0) {
		perror("Incorrect arguments!\n");
		exit(1);
	}
	return 0;
}
