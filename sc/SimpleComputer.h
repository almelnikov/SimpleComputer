#ifndef __GUARD_SIMLECOMPUTER_H
#define __GUARD_SIMLECOMPUTER_H

#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include "myTerm.h"
#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myReadkey.h"

extern int inst_counter;
extern int accumulator;
extern int big_chars[256];
extern int cursor_pos;
extern int write_used, write_val;

void print_keys(int x, int y);
void print_flags(int x, int y);
void print_memory(int x, int y, int position);
void print_boxes();
void print_labels();
void print_counter();
int print_mcell(int *bigchars, int pos);
void print_operation(int position);
void refresh_gui(int position);
int scan_num(int *plus_flag, int *n);
int change_acc(int pos);
int change_cnt(int pos);
int change_mcell(int pos);
int read_mcell(int pos);
int memory_save(int position);
int memory_load(int position);
void set_signals();
void timer_handler();
void usrsig_handler();
void CU();
int ALU(int command, int operand);
int main();

#endif /* __GUARD_SIMLECOMPUTER_H */
