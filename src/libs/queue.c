#include "include/queue.h"

void init_queue(Queue *q) {
    q->head = 0;
    q->tail = 0;
}

int enqueue(Queue *q, char *token) {
    int flag = 1;

    if (q->tail >= MAX_TOKENS - 1) {
        flag = 0;
    } else {
        strncpy(q->tokens[q->tail], token, MAX_TOKEN_LENGTH - 1);
        q->tokens[q->tail][MAX_TOKEN_LENGTH - 1] = '\0';
        q->tail++;
    }
    return flag;
}

char *dequeue(Queue *q) {
    if (q->head == q->tail) return NULL;

    char *token = q->tokens[q->head];
    q->head++;
    return token;
}

void reset_queue(Queue *q) { q->head = 0; }