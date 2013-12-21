#ifndef GUARD_RPN
#define GUARD_RPN

#include <stdio.h>
#include <stdlib.h>

struct stack_t {
	char c;
	struct stack_t *next;
};

struct stack_t *stack_push(struct stack_t *head, char a);
char stack_pop(struct stack_t **head);
int get_prior(char c);
void translate_to_rpn(char *outstr, char *a);

#endif
