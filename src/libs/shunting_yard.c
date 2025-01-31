#include "include/shunting_yard.h"

int isNumber(char* token) {
    int flag = 1;
    if (atoi(token) == 0 && token[0] != '0') {
        flag = 0;
    }
    return flag;
}

int isDigit(char ch) { return strchr("0123456789", ch) != NULL; }

int isOperator(char* token) { return strchr("+-*/", token[0]) != NULL; }

int precedence(char* token) {
    int result = 0;

    if (strchr("+-", token[0]) != NULL) {
        result = 1;
    }
    if (strchr("*/", token[0]) != NULL) {
        result = 2;
    }

    if (isFunction(token)) {
        result = 3;
    }

    if (token[0] == '~') {
        result = 4;
    }

    return result;
}

int isFunction(char* token) {
    return strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 ||
           strcmp(token, "ctg") == 0 || strcmp(token, "sqrt") == 0 || strcmp(token, "ln") == 0;
}

void shuntingYard(char* tokens[], Stack* stack, Queue* queue) {
    for (int i = 0; tokens[i] != NULL; i++) {
        char* token = tokens[i];

        if (isNumber(token) || !strcmp(token, "x")) {
            enqueue(queue, token);

        } else if (token[0] == '(') {
            push(stack, token);

        } else if (token[0] == ')') {
            while (stack->top >= 0 && stack->tokens[stack->top][0] != '(') {
                enqueue(queue, pop(stack));
            }
            pop(stack);

        } else if (isOperator(token)) {
            while (stack->top >= 0 && precedence(stack->tokens[stack->top]) >= precedence(token)) {
                enqueue(queue, pop(stack));
            }
            push(stack, token);

        } else if (isFunction(token)) {
            while (stack->top >= 0 && precedence(stack->tokens[stack->top]) >= precedence(token)) {
                enqueue(queue, pop(stack));
            }
            push(stack, token);

        } else if (token[0] == '~') {
            while (stack->top >= 0 && precedence(stack->tokens[stack->top]) >= precedence(token)) {
                enqueue(queue, pop(stack));
            }
            push(stack, token);
        }
    }

    while (stack->top >= 0) {
        enqueue(queue, pop(stack));
    }
}