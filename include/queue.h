#pragma once

#include "value.h"
#include "node.h"

typedef struct {
    node_t* head;
    node_t* tail;
    int count;
} queue_t;

void initQueue(queue_t* q);
Value popQueue(queue_t* q);
void addQueue(queue_t* q, Value value);
int queueCount(queue_t* q);
void printQueue(queue_t* q);