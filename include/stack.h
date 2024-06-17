#pragma once

#include "node.h"
#include "value.h"

typedef struct {
    node_t* top;
    int count;
} stack_t;

int stackSize(stack_t* stack);
void initStack(stack_t* stack);
Value stackPop(stack_t* stack);
void stackPush(stack_t* stack, Value value);
void printStack(stack_t* stack);