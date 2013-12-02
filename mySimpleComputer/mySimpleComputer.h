#ifndef __GUARD_MYSIMPLECOMPUTER_H
#define __GUARD_MYSIMPLECOMPUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MEMSIZE 100

#define FLAG_OVERFLOW 0
#define FLAG_DIVISION 1
#define FLAG_OUTMEM 2
#define FLAG_INTERRUPT 3
#define FLAG_COMMAND 4
#define FLAG_ODD 5

#define ERR_WRONG_ADDR -1
#define ERR_OPEN_FILE -2
#define ERR_FILE_SIZE -3
#define ERR_UNCORRECT_COMMAND -4
#define ERR_ATTRIBUTE_BIT -5
#define ERR_WRONG_FLAG -6

#define BIT_SET(A, B) (A =((A) | (1 << (B))))
#define BIT_CLEAR(A, B) (A = ((A) & ~(1 << (B))))
#define BIT_CHECK(A, B) (((A) >> B) & 1)

extern int sc_memory[MEMSIZE];
extern int sc_reg_flags;
extern const int correct_ops[];
extern const int ops_num;

int int_cmp(const void *a, const void *b);
int sc_memoryInit();
int sc_memorySet(int addr, int value);
int sc_memoryGet(int addr, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int *value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);

#endif /* __GUARD_MYSIMPLECOMPUTER_H */