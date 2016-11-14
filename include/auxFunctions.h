#ifndef AUXFUNCTIONS_H
#define AUXFUNCTONS_H

/* Function used to compare strings, used to sort
 * the vector using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int alphaCompare (const void* a, const void* b);

/* Function used to compare integers, used to sort
 * the vector using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int numCompare (const void* a, const void* b);

/* Function used to compare strings, used to sort
 * the linked list using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int alphaCompareList (const void* a, const void* b);

/* Function used to compare integers, used to sort
 * the linked list using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int numCompareList (const void* a, const void* b);

/* Function used to compare integers, used to sort
 * the binary tree using qsort.
 * Retrun 1, if a > b, -1, if a < b, and 0 otherwise*/
int numCompareBT (const void* a, const void* b);

/* Receives a symbol table pointer, a key and a flag.
 * Return the position if the key is found in the table
 * and set the flag to 1.
 * Return the position where the key should be inserted
 * and set the flag to 0, otherwise.*/
int binarySearch(STableVec* table, char* key, int* found);

#endif
