#include <stdlib.h>
#include <string.h>
#include "../include/readWord.h"
#include "../include/types.h"

STable* STable_create(int size) {

    int j;
    STable* stable = malloc (sizeof(STable)); 
    stable->data = malloc (size * sizeof(Entry));
    stable->size = size;
    stable->count = 0;
    
    /*Make sure that the frequencies are zero. */
    for (j = 0; j < size; j++)
        stable->data[j].info = 0;
    
    return stable;
}

void STable_destroy(STable* table) {

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

STable* STable_realloc(STable* table) {
    int i;
    STable* new;

    new = STable_create(table->size*2);
    new->count = table->count;

    for (i = 0; i < table->size; i++) {
        new->data[i].key = malloc(strlen(table->data[i].key));
        new->data[i].key = strcpy(new->data[i].key, table->data[i].key);
        new->data[i].info = table->data[i].info;
    }

    STable_destroy(table);
    return(new);
}

int binarySearch(STable* table, char* key, int* found) {
    int beg, end, mid;
    beg = 0;
    end = table->count;
    found = 0;
    while(beg <= end) {
        mid = (beg + end)/2;
        if (strcmp(table->data[mid].key, key) == 0) {
            found = 1;
            return mid;
        }
        else if (strcmp(table->data[mid].key, key) == 1)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return(end);
}

void STable_insert(STable* table, char* key) {
    int i, j, found;
    short int cmp;

    i = binarySearch(table, key, &found);

    if (found == 0) {
        for (j = table->count; j > i; j--) {
            table->data[j].key = malloc(strlen(table->data[j - 1].key));
            strcpy(table->data[j].key, table->data[j - 1].key);
            table->data[j].info = table->data[j - 1].info;
            free(table->data[j -  1].key);
        }
        table->data[i].key = malloc(strlen(key));
        strcpy(table->data[i].key, key);
        table->data[i].info++;
        table->count++;
    }

    else
        table->data[i].info++;
}

void STable_printAlpha(STable* table) {
    int i;
    for (i = 0; i < table->size && table->data[i].info; i++) {
        printf("%s ", table->data[i].key);
        printf("%d\n", table->data[i].info);
    }
}

void STable_printNum (STable* table) {
    int i;
    for (i = table->count - 1; i >= 0; i--) {
        printf("%s ", table->data[i].key);
        printf("%d\n", table->data[i].info); 
    }
}

int numCompare (const void* a, const void* b) {
  if ((*(Entry*)a).info < (*(Entry*)b).info) return -1;
  if ((*(Entry*)a).info == (*(Entry*)b).info) return 0;
  if ((*(Entry*)a).info > (*(Entry*)b).info) return 1;
  return 0;
}

void desorderVec(FILE* file, char* mode) {
    int end;
    char* str;
    
    STable* stable = STable_create(1024);
    end = 0;
    while (end == 0) {
        str = readWord(file, &end);
        STable_insert(stable, str);
    }

    if ((strcmp(mode, "O")) == 0) {
        qsort(stable->data, stable->count, sizeof(Entry), numCompare);
        STable_printNum (stable);
    }
    else
        STable_printAlpha(stable);

    return;
}
