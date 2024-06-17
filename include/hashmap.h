#pragma once

#include <stdbool.h>
#include "node.h"
#include "value.h"

typedef struct {
    int count;
    int capacity;
    node_t* entries;
} HashMap;

void initNewHashMap(HashMap* map);
void freeHashMap(HashMap* map);
void mapPut(HashMap* map, char* key, Value* value);
Value* mapGet(HashMap* map, char* key);
bool mapHas(HashMap* map, char* key);
void printHashMap(HashMap* map);