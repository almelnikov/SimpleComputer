#include "mySimpleComputer.h"

int sc_memory[MEMSIZE];
int sc_reg_flags; // Регистр флагов
const int correct_ops[] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43};
const int ops_num = 12;
