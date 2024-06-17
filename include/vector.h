#pragma once

#include <stdio.h>
#include "node.h"
#include "value.h"

#define GROWTH_FACTOR 2
#define INITIAL_CAPACITY 8

typedef struct {
    Value* values;
    size_t size;
    size_t capacity;
} vector_t;

void initVector(vector_t* vector);
void addVector(vector_t* vector, Value value);
void removeItemVector(vector_t* vector, Value value);
Value itemAtVector(vector_t* vector_t, int index);
void freeVector(vector_t* vector);
void printVector(vector_t* vector);

