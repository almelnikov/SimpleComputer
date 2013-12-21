#ifndef GUARD_BASIC
#define GUARD_BASIC

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rpn.h"

struct b_label {
	int label;
	int pos;
};

struct memory_t {
	int is_val;
	int command;
	int operand;
};

enum keywords {
	KEYW_REM = 1,
	KEYW_INPUT = 2,
	KEYW_OUTPUT = 3,
	KEYW_GOTO = 4,
	KEYW_IF = 5,
	KEYW_LET = 6,
	KEYW_END = 7,
	KEYW_E = -1
};

#endif