#include "mySimpleComputer.h"


int sc_memoryInit()
{
	memset(sc_memory, 0, sizeof(*sc_memory));
	return 0;
}
