#ifndef STABLELLIST_H
#define STABLELLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

/* Receives a char pointer and create a node 
 * for the linked list with the given list */
node* Node_create (char* key);

/* Receives a symbol table pointer with the head
 * of the linked list and free every node of the 
 * list, until it's all freed. */
node* STableList_destroy (STableList* nd);

/* Receives symbol table pointer and a char pointer,
 * insert the key, if the key is new, in the end 
 * of the linked list or sums one into the info field,
 * otherwise.
 * Returns the symbol table pointer with the head of the
 * linked list. */
STableList* STableList_simpleInsert (STableList* table, char* key);

/* Receives symbol table pointer and a char pointer,
 * insert the key, if the key is new, in the its proper
 * place in the linked list, considering the alphabetical 
 * order of the words or sums one into the info field,
 * otherwise.
 * Returns the symbol table pointer with the head of the
 * linked list. */
STableList* STableList_orderInsert (STableList* table, char* key);

/* Receives a symbol table pointer with the head of the
 * linked list, runs a qsort on the list, so it can be
 * printed in the alphabetical order. */
void STableList_alphaPrint (STableList* table);

/* Receives a symbol table pointer with the head of the
 * linked list and prints it the same way as the table
 * is received. */
void STableList_normalPrint (STableList* table);

/* Receives a symbol table pointer with the head of the
 * linked list, runs a qsort on the list, so it can be
 * printed in the numerical order. */
void STableList_numPrint (STableList* table);

#endif
