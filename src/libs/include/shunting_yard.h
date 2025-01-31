#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "queue.h"
#include "stack.h"

int isNumber(char* token);
int isDigit(char ch);
int isOperator(char* token);
int precedence(char* op);
int isFunction(char* token);
void shuntingYard(char* tokens[], Stack* stack, Queue* queue);

#endif