#pragma once

#include "value.h"
#include "node.h"

typedef struct {
    node_t* head;
    node_t* tail;
    int count;
} queue_t;

void initQueue(queue_t* q);
Value deqeue(queue_t* q);
void enqueue(queue_t* q, Value value);
int queueSize(queue_t* q);
void printQueue(queue_t* q);