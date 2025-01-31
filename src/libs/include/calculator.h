#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "shunting_yard.h"

double computeOperations(char op, double num1, double num2);
double computeFunc(char* token, double num1);
double calculations(Queue* queue, double x);

#endif