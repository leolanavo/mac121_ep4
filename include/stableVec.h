#ifndef STABLEVEC_H
#define STABLEVEC_H

#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

/* Receives an integer, which will be the size of the
 * symbol table. Return an allocted symbol table pointer
 * with all of its frequencies set to 0.*/
STable* STable_create(int size);

/* Receives a symbol table pointer, and free all of its
 * allocted components. */
void STable_destroy(STable* table);

/* Receives a symbol table pointer, and returns another
 * symbol table pointer with double the size of the orginal
 * allocted and with the same content as well.*/
STable* STable_realloc(STable* table);

/* Receives a symbol table pointer and a string, it will
 * simply insert the string in the first free position,
 * but if the string is found in the symbol table, it will
 * just sums 1 in the info section of the Entry struct. */
void STable_simpleInsert(STable* table, char* key);

/* Receives a symbol table pointer and a string, it will
 * search for the right place the to insert the string in
 * the table, and changes the table to correctly insert
 * the string. In case, it finds the string in the table,
 * it will just sums 1 in the info section of the Entry
 * struct. */
void STable_orderInsert(STable* table, char* key);

/* Receives a symbol table pointer and prints it in the
 * correct order. */
void STable_printOrder (STable* table);

/* Receives a symbol table pointer and prints it in the
 * reverse order. */
void STable_printReverse (STable* table);

#endif
