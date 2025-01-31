#ifndef STACK_H
#define STACK_H

#include "config.h"

typedef struct {
    int top;
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
} Stack;

typedef struct {
    int top;
    double values[MAX_TOKENS];
} Calculation_stack;

void init_stack(Stack *stack);
int push(Stack *stack, char *token);
char *pop(Stack *stack);

void init_cal_stack(Calculation_stack *stack);
int cal_push(Calculation_stack *stack, double value);
double cal_pop(Calculation_stack *stack);

#endif