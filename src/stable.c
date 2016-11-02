#include <stdlib.h>
#include "../include/type.h"

SymbolTable stable_create(int size) {

    int j;
    STable* stable = malloc (sizeof(STable)); 
    stable->data = malloc (size * sizeof(Entry));
    stable->size = size;
    stable->index = 0;
    
    /*Make sure that the frequencies are zero. */
    for (j = 0; j < size; j++)
        stable->data[j].info = 0;
    
    return stable;
}