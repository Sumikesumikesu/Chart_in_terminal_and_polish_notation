#include "include/stack.h"

void init_stack(Stack *stack) { stack->top = -1; }

int push(Stack *stack, char *token) {
    int flag = 1;

    if (stack->top >= MAX_TOKENS - 1) {
        flag = 0;
    } else {
        stack->top++;
        strncpy(stack->tokens[stack->top], token, MAX_TOKEN_LENGTH - 1);
        stack->tokens[stack->top][MAX_TOKEN_LENGTH - 1] = '\0';
    }
    return flag;
}

char *pop(Stack *stack) {
    if (stack->top < 0) {
        return NULL;
    }
    char *token = stack->tokens[stack->top];
    stack->top--;
    return token;
}

void init_cal_stack(Calculation_stack *stack) { stack->top = -1; }

int cal_push(Calculation_stack *stack, double value) {
    if (stack->top >= MAX_TOKENS - 1) {
        return 0;
    } else {
        stack->top++;
        stack->values[stack->top] = value;
        return 1;
    }
}

double cal_pop(Calculation_stack *stack) {
    if (stack->top < 0) {
        return 0.0;
    } else {
        double value = stack->values[stack->top];
        stack->top--;
        return value;
    }
}