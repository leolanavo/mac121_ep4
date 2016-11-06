#ifndef STABLEBT_H
#define STABLEBT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

/**/
nodeBT* NodeBT_create (char* key);

/**/
void NodeBT_destroy (nodeBT* root);

/**/
nodeBT* NodeBT_search (nodeBT* root, char* key);

/**/
STableBT* STableBT_insert (STableBT* table, char* key);

/**/
nodeBT* NodeBT_remove (nodeBT* root, char* key);

/**/
void NodeBT_print (nodeBT* root);

/**/
void STableBT_numPrint (STableBT* table);

#endif