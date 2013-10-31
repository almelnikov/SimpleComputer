#include "mySimpleComputer.h"

int sc_memory[MEMSIZE];
int sc_reg_flags; // Регистр флагов
const int correct_ops[] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43};
const int ops_num = 12;


int int_cmp(const void *a, const void *b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else
	if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}

int sc_memoryInit()
{
	memset(sc_memory, 0, sizeof(*sc_memory));
	return 0;
}

int sc_memorySet(int address, int value)
{
	if ((address >= 0) && (address < MEMSIZE)) {
		sc_memory[address] = value;
		return 0;
	}
	else
		return ERR_WRONG_ADDR;
}

int sc_memoryGet(int address, int *value)
{
	if ((address >= 0) && (address < MEMSIZE)) {
		*value = sc_memory[address];
		return 0;
	}
	else
		return ERR_WRONG_ADDR;
}

int sc_memorySave(char *filename)
{
	FILE *save;
	int nwritten;
	
	save = fopen(filename, "wb");
	if (save == NULL)
		return ERR_OPEN_FILE;
	nwritten = fwrite(sc_memory, 1, sizeof(*sc_memory) * 100, save);
	fclose(save);
	if (nwritten != 1)
		return ERR_FILE_SIZE;
	else
		return 0;
}

int sc_memoryLoad(char *filename)
{
	FILE *save;
	int nreaden;
	
	save = fopen(filename, "rb");
	if (save == NULL)
		return ERR_OPEN_FILE;
	nreaden = fread(sc_memory, 1, sizeof(*sc_memory) * 100, save);
	fclose(save);
	if (nreaden != 1)
		return ERR_FILE_SIZE;
	else
		return 0;
}

int sc_regInit()
{
	sc_reg_flags = 0;
	return 0;
}

int sc_regSet(int reg, int value)
{

	if ((reg >= 0) && (reg <=4)) {
		if (value == 1)
			BIT_SET(sc_reg_flags, reg);
		else if (value == 0)
			BIT_CLEAR(sc_reg_flags, reg);
		else
			return 0;
		
	}
	else
		return ERR_WRONG_FLAG;
	return 0;
}

int sc_regGet(int reg, int *value)
{
	if ((reg >= 0) && (reg <=4)) {
		*value = BIT_CHECK(sc_reg_flags, reg);
	}
	else
		return ERR_WRONG_FLAG;
	return 0;
}

int sc_commandEncode(int command, int operand, int *value)
{
	void *command_ptr;
	
	command_ptr = bsearch(&command, correct_ops, ops_num, sizeof(int), int_cmp);
	if (command_ptr != NULL) {
		*value = (command << 7) | operand | 0x4000;
		return 0;
	}
	else
		return ERR_UNCORRECT_COMMAND;
}

int sc_commandDecode(int value, int *command, int *operand)
{
	void *correct_command;
	int attribute;
	int tmp_command, tmp_operand;
	
	attribute = (value >> 14) & 1;
	if (attribute) {
		tmp_command = (value >> 7) & 0x7F;
		tmp_operand = value & 0x7F;
		correct_command = bsearch(&tmp_command, correct_ops, ops_num,
								  sizeof(int), int_cmp);
		if (correct_command != NULL) {
			*command = tmp_command;
			*operand = tmp_operand;
		}
		else
			return ERR_UNCORRECT_COMMAND;
	}
	else
		return ERR_ATTRIBUTE_BIT;
	return 0;
}
