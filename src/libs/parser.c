#include "include/parser.h"

int add_token(char *tokens[], int *token_count, char *buffer, int token_length) {
    int flag = 1;

    buffer[token_length] = '\0';
    tokens[*token_count] = strdup(buffer);

    if (tokens[*token_count] == NULL) {
        flag = 0;
    }

    (*token_count)++;
    return flag;
}

void parse_string(char *input, char *tokens[], int *token_count) {
    char delimiters[] = "+-*/()~";
    int buffer_length = 0;
    char buffer[MAX_TOKEN_LENGTH];

    for (int i = 0; input[i] != '\0'; i++) {
        if (strchr(delimiters, input[i]) != NULL) {
            if (buffer_length > 0) {
                add_token(tokens, token_count, buffer, buffer_length);
                buffer_length = 0;
            }

            buffer[0] = input[i];
            buffer[1] = '\0';
            add_token(tokens, token_count, buffer, 1);

        } else {
            buffer[buffer_length++] = input[i];
        }
    }
    if (buffer_length > 0) {
        add_token(tokens, token_count, buffer, buffer_length);
    }
    tokens[*token_count] = NULL;
    *token_count += 1;
}

void removeSpaces(char *str) {
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

void addZero(char *str, char ch) {
    size_t len = strlen(str);
    for (size_t i = len; i > 0; i--) {
        str[i] = str[i - 1];
    }
    str[0] = ch;
}

void replaceUnaryMinus(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '-' && i > 0 && str[i - 1] == '(' && (isDigit(str[i + 1]) || str[i + 1] == 'x')) {
            str[i] = '~';
        }
        i++;
    }
}