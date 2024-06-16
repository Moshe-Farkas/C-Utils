#include <stdbool.h>

typedef int entry;

typedef struct {
    int count;
    int capacity;
    entry* entries;
} HashMap;

void initNewHashMap(HashMap* map);
void freeHashMap(HashMap* map);
void mapPut(HashMap* map, char* key, entry* value);
entry* mapGet(HashMap* map, char* key);
bool mapHas(HashMap* map, char* key);
void printHashMap(HashMap* map);