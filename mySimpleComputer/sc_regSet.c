#include "mySimpleComputer.h"

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
