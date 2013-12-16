#include "SimpleComputer.h"

static void print_write_val()
{
	int command, opcode, operand;

	mt_gotoXY(1, 23);
	command = (write_val >> 14) & 1;
	opcode = (write_val >> 7) & 0x7F;
	operand = write_val & 0x7F;
	if (write_used != 0) {
		printf("Last WRITE: ");
		if (command == 0)
			printf("+%02X%02X", opcode, operand);
		else
			printf(" %02X%02X", opcode, operand);	
	}
}

void refresh_gui(int position)
{
	mt_clrscr();
	print_boxes();
	print_labels();
	print_keys(48, 14);
	print_counter();
	/* print accumulator */
	mt_gotoXY(70, 2);
	printf("%04X", accumulator);
	print_operation(position);
	print_memory(2, 2, position);
	print_flags(68, 11);
	print_mcell(big_chars, position);
	print_write_val();
	mt_gotoXY(1, 24);
}
