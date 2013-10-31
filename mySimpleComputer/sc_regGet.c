#include "mySimpleComputer.h"

int sc_regGet(int reg, int *value)
{
	if ((reg >= 0) && (reg <=4)) {
		*value = BIT_CHECK(sc_reg_flags, reg);
	}
	else
		return ERR_WRONG_FLAG;
	return 0;
}
