#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "value.h"

void initVector(vector_t* vector) {
    vector->size = 0;
    vector->values = malloc(sizeof(Value) * 8);
    if (vector->values == NULL) {
        printf("buy more ram");
        exit(1);
    }
    vector->capacity = 8;
}

void resizeVector(vector_t* vector) {
    size_t newSize = vector->capacity * GROWTH_FACTOR;
    vector->values = realloc(vector->values, newSize);
    if (vector->values == NULL) {
        printf("buy more ram");
        exit(1);
    }
    vector->capacity = newSize;
}

void addVector(vector_t* vector, Value value) {
    if (vector->size == vector->capacity) {
        resizeVector(vector);
    }
    vector->values[vector->size++] = value;
}

void freeVector(vector_t* vector) {
    free(vector->values);
    vector->capacity = 0;
    vector->size = 0;
}

Value itemAtVector(vector_t* vector, int index) {
    if (index > vector->size || index < 0) {
        Value empty = {-1};
        return empty;
    }
    return vector->values[index];
}

void removeItemVector(vector_t* vector, Value value) {

}

void printVector(vector_t* vector) {
    if (vector->size == 0)
        return;
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->values[i].int_v);
    }
    printf("\n");
}