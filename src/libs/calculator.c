#include "include/calculator.h"

double computeOperations(char op, double num1, double num2) {
    double result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;

        default:
            result = NAN;
            break;
    }
    return result;
}

double computeFunc(char *token, double num1) {
    double result;

    if (strcmp(token, "sin") == 0) {
        result = sin(num1);

    } else if (strcmp(token, "cos") == 0) {
        result = cos(num1);

    } else if (strcmp(token, "tan") == 0) {
        result = tan(num1);

    } else if (strcmp(token, "ctg") == 0) {
        result = 1.0 / tan(num1);

    } else if (strcmp(token, "sqrt") == 0) {
        result = sqrt(num1);

    } else if (strcmp(token, "ln") == 0) {
        result = log(num1);

    } else if (token[0] == '~') {
        result = num1 * (-1);

    } else {
        result = NAN;
    }

    return result;
}

double calculations(Queue *queue, double x) {
    Calculation_stack cal_stack;
    init_cal_stack(&cal_stack);
    double result;

    char *token;
    while ((token = dequeue(queue)) != NULL) {
        if (isNumber(token)) {
            cal_push(&cal_stack, atof(token));

        } else if (token[0] == 'x') {
            cal_push(&cal_stack, x);

        } else if (isOperator(token) == 1) {
            double num2 = cal_pop(&cal_stack);
            double num1 = cal_pop(&cal_stack);

            result = computeOperations(token[0], num1, num2);
            cal_push(&cal_stack, result);

        } else if (isFunction(token) == 1) {
            double num1 = cal_pop(&cal_stack);

            result = computeFunc(token, num1);
            cal_push(&cal_stack, result);

        } else if (token[0] == '~') {
            double num1 = cal_pop(&cal_stack);

            result = computeFunc(token, num1);
            cal_push(&cal_stack, result);
        }
    }
    result = cal_pop(&cal_stack);
    reset_queue(queue);

    return result;
}