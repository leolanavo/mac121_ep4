#include <stdlib.h>
#include <string.h>
#include "../include/readWord.h"
#include "../include/types.h"

STable* stable_create(int size) {

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

STable* reallocSTable(STable* table) {
    short int cmp;
    int i, ind;
    STable* new;

    new = stable_create(table->size*2);
    
    for (i = 0; i < table->size; i++) {
        strcpy(new->data[i].key, table->data[i].key);
        new->data[ind].input->i = table->data[i].input->i;
    }

    stable_destroy(table)
    return(new->data);
}

void stable_destroy(STable* table) {

    int i;
    
    for (i = 0; i < table->size; i++) {
        free(table->data[i].key);
        table->data[i].key = NULL;
    }
    
    free(table->data);
    table->data = NULL;
    free(table);
    table = NULL;
    
}

void stable_insert(STable* table, char* key) {
    int i
    short int cmp;
    
    for (i = 0; table->data[i].info == 0 && 
        (cmp = strcmp(table->data[i].key, key)); i++) {
        
        if (i == table->size)
            stable = reallocSTable(table);
    }

    if (stable->data[i].info == 0) {
        strcpy(table->data[i].key, key)
        table->data[i]++;
    }

    else
        table->data[i]++;
}

void stable_print(STable* table) {
    int i;
    for (i = 0; i < table->size, table->data[i].info; i++) {
        printf("%s ", table->data[i].key);
        printf("%d\n", table->data[i].info);
    }
}

int alphaCompare (const void* a, const void* b) {
    return (strcmp((*(Entry*)a).key, (*(Entry*)b).key));
}

int compareMyType (const void* a, const void* b) {
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}

void desorderVec(FILE* file, char* mode) {
    int end, size;
    char* str;
    end = 0;
    STable* stable = stable_create(1024);

    while (end == 0) {
        str = readWord(file, &end);
        stable_insert(srt);
    }

    if (mode == "A")
        qsort(stable->data, stable->size, sizeof(Entry), alphaCompare);
    else
        qsort(stable->data, stable->size, sizeof(Entry), numCompare);

    stable_print(stable);
    return;
}