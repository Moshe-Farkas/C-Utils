#pragma once

#include "value.h"

typedef struct node {
    Value value;
    struct node* next;
} node_t;
