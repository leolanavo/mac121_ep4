#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"
#include "../include/stableVec.h"

/* Receives an integer, which will be the size of the
 * symbol table. Return an allocted symbol table pointer
 * with all of its frequencies set to 0.*/
STableVec* STableVec_create(int size) {

    int j;
    STableVec* stable = malloc (sizeof(STableVec)); 
    stable->data = malloc (size * sizeof(Entry));
    stable->size = size;
    stable->count = 0;
    
    /*Make sure that the frequencies are zero. */
    for (j = 0; j < size; j++)
        stable->data[j].info = 0;
    
    return stable;
}

/* Receives a symbol table pointer, and free all of its
 * allocted components. */
void STableVec_destroy(STableVec* table) {

    int i;
    
    for (i = 0; i < table->count; i++) {
        free(table->data[i].key);
        table->data[i].key = NULL;
    }
    
    free(table->data);
    table->data = NULL;
    free(table);
    table = NULL;

}

/* Receives a symbol table pointer, and returns another
 * symbol table pointer with double the size of the orginal
 * allocted and with the same content as well.*/
STableVec* STableVec_realloc(STableVec* table) {
    int i;
    STableVec* new;

    new = STableVec_create(table->size*2);
    new->count = table->count;

    for (i = 0; i < table->size; i++) {
        new->data[i].key = malloc(strlen(table->data[i].key));
        new->data[i].key = strcpy(new->data[i].key, table->data[i].key);
        new->data[i].info = table->data[i].info;
    }

    STableVec_destroy(table);
    return(new);
}

/* Receives a symbol table pointer and a string, it will
 * simply insert the string in the first free position,
 * but if the string is found in the symbol table, it will
 * just sums 1 in the info section of the Entry struct. */
void STableVec_simpleInsert(STableVec* table, char* key) {
    int i;
    short int cmp;
    
    for (i = 0; table->data[i].key &&  
        (cmp = strcmp(table->data[i].key, key)); i++) {
        
        if (i == table->size)
            table = STableVec_realloc(table);
    }

    if (table->data[i].key == NULL) {
        table->data[i].key = malloc(strlen(key));
        strcpy(table->data[i].key, key);
        table->data[i].info++;
        table->count++;
    }

    else
        table->data[i].info++;
}

/* Receives a symbol table pointer and a string, it will
 * search for the right place the to insert the string in
 * the table, and changes the table to correctly insert
 * the string. In case, it finds the string in the table,
 * it will just sums 1 in the info section of the Entry
 * struct. */
void STableVec_orderInsert(STableVec* table, char* key) {
    int i, j, found;
    
    if (table->count == table->size)
        table = STableVec_realloc(table);
    
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
        table->data[i].info = 1;
        table->count++;
    }

    else
        table->data[i].info++;

}

/* Receives a symbol table pointer and prints it in the
 * correct order. */
void STableVec_print (STableVec* table) {
    int i;
    for (i = 0; i < table->count; i++) {
        printf("%s ", table->data[i].key);
        printf("%d\n", table->data[i].info);
    }
}

/* Receives a symbol table pointer and prints it in the
 * reverse order. */
void STableVec_reversePrint (STableVec* table) {
    int i;
    for (i = table->count - 1; i >= 0; i--) {
        printf("%s ", table->data[i].key);
        printf("%d\n", table->data[i].info);
    }
}
