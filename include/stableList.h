#ifndef STABLELLIST_H
#define STABLELLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

/**/
node* Node_create (char* key);

/**/
node* STableList_destroy (STableList* nd);

/**/
STableList* STableList_simpleInsert (STableList* table, char* key);

/**/
STableList* STableList_orderInsert (STableList* table, char* key);

/**/
void STableList_alphaPrint (STableList* table);

/**/
void STableList_normalPrint (STableList* table);

/**/
void STableList_numPrint (STableList* table);

#endif
