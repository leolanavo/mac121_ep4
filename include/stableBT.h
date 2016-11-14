#ifndef STABLEBT_H
#define STABLEBT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

/* Receives a char pointer and creates a pointer to a
 * nodeBT, with the given key and left and right pointers
 * null.*/
nodeBT* NodeBT_create (char* key);

/* Receives a nodeBT pointer for the root of the binary tree
 * and it will free all the nodes from the tree. */
void NodeBT_destroy (nodeBT* root);

/* Receives a nodeBT pointer to the root of the binary tree
 * and free recursively the leaves until the whole tree
 * is freed. */
nodeBT* NodeBT_search (nodeBT* root, char* key);

/* Receives a symbol table pointer and a char pointer.
 * Insert the given key into the binary tree, if the key 
 * is new, or sums one into the info field, otherwise.
 * Return the symbol table, i.e. the root of the binary
 * tree. */
STableBT* STableBT_insert (STableBT* table, char* key);

/* Receives a nodeBT pointer to the root of the binary tree
 * and go through the binary tree in order and print it. */
void NodeBT_print (nodeBT* root);

/* Receives a symbol table pointer and print it according
 * to the frequencies of the word. */
void STableBT_numPrint (STableBT* table);

#endif
