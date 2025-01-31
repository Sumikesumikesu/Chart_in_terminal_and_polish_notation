#ifndef PARSER_H
#define PARSER_H

#include "shunting_yard.h"

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

int add_token(char *tokens[], int *token_count, char *buffer, int token_length);
void parse_string(char *input, char *tokens[], int *token_count);
void removeSpaces(char *str);
void replaceUnaryMinus(char *str);
void replaceUnaryMinus(char *str);

#endif