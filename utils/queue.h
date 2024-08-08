#ifndef QUEUE_H
#define QUEUE_H

#include "nodes.h"

typedef struct Queue {
    node *first;
    node *last;
    int size;
} Queue;

void initializeQueue(Queue *q);
void appendQueue(char *data, Queue *q);
void printQueue(Queue *q);

#endif