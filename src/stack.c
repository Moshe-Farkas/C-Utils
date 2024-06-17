#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void initStack(stack_t* stack) {
    stack->top = NULL;
    stack->count = 0;
}

int stackSize(stack_t* stack) {
    return stack->count;
}

void stackPush(stack_t* stack, Value v) {
    stack->count++;
    node_t* newNode = malloc(sizeof(node_t));
    newNode->value = v;

    if (stack->top == NULL) {
        newNode->next = NULL;
        stack->top = newNode;
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

Value stackPop(stack_t* stack) {
    if (stack->top == NULL) {
        Value empty = {-1};
        return empty;
    }
    stack->count--;
    node_t* temp = stack->top;
    Value retVal = temp->value;
    stack->top = stack->top->next;
    free(temp);
    return retVal;
}

void printStack(stack_t* stack) {
    for (node_t* iter = stack->top; iter != NULL; iter = iter->next) {
        printf("%d-> ", iter->value.int_v);
    }
    printf("\n");
}