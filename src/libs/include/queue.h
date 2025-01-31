#ifndef QUEUE_H
#define QUEUE_H

#include "config.h"

typedef struct {
    int head;
    int tail;
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
} Queue;

void init_queue(Queue *q);
int enqueue(Queue *q, char *token);
char *dequeue(Queue *q);
void reset_queue(Queue *q);

#endif