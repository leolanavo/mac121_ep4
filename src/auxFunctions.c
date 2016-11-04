#include <stdlib.h>
#include <string.h>
#include "../include/types.h"

/* Function used to compare strings, used to sort
 * the vector using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int alphaCompare (const void* a, const void* b) {
    return (strcmp((*(Entry*)a).key, (*(Entry*)b).key));
}

/* Function used to compare integers, used to sort
 * the vector using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int numCompare (const void* a, const void* b) {
  if ((*(Entry*)a).info < (*(Entry*)b).info) return -1;
  if ((*(Entry*)a).info == (*(Entry*)b).info) return 0;
  if ((*(Entry*)a).info > (*(Entry*)b).info) return 1;
  return 0;
}

/* Receives a symbol table pointer, a string and a flag.
 * Return the position if the key is found in the table
 * and set the flag to 1.
 * Return the position where the key should be inserted
 * and set the flag to 0, otherwise.*/
int binarySearch(STable* table, char* key, int* found) {
    int beg, end, mid;
    beg = 0;
    end = table->count;
    *found = 0;
    while(beg <= end) {
        mid = (beg + end)/2;
        if (table->data[mid].key != NULL && (strcmp(table->data[mid].key, key) == 0)) {
            *found = 1;
            return mid;
        }
        else if (table->data[mid].key && (strcmp(table->data[mid].key, key) == 1))
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return(end);
}
