#include <stdio.h>
#include "hashmap.h"

bool mapHas(HashMap* mape, char* key) {
    return false;
}

void initNewHashMap(HashMap* map) {
    map->capacity = 0;
    map->count = 0;    
    map->entries = NULL;
}

void printHashMap(HashMap* map) {
    printf("map count: %d\n", map->count);
    printf("map capacity: %d\n", map->capacity);
}

void mapPut(HashMap* map, char* key, Value* value) {
    map->count++;
}