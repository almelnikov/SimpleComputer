#include "mySimpleComputer.h"

int sc_commandEncode(int command, int operand, int *value)
{
	void *command_ptr;
	
	command_ptr = bsearch(&command, correct_ops, ops_num, sizeof(int), int_cmp);
	if (command_ptr != NULL) {
		*value = (command << 7) | operand;
		return 0;
	}
	else
		return ERR_UNCORRECT_COMMAND;
}
