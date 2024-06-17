#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void initQueue(queue_t* q) {
    q->head = q->tail = NULL;
    q->count = 0;
}

int queueCount(queue_t* q) {
    return q->count;
}

void addQueue(queue_t* q, Value v) {
    q->count++;
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->value = v;
    newNode->next = NULL;

    if (q->head == NULL) {
        q->head = q->tail = newNode;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;
}

Value popQueue(queue_t* q) {
    if (q->head == NULL) {
        Value empty = {-1};
        return empty;
    }
    q->count--;
    node_t* temp = q->head;
    Value retVal = temp->value; 
    q->head = q->head->next;
    free(temp);

    return retVal;
}

void printQueue(queue_t* q) {
    printf("head-> ");
    for (node_t* iter = q->head; iter != NULL; iter = iter->next) {
        printf("%d-> ", iter->value.int_v);
    }
    printf("tail");
    printf("\n");
}
