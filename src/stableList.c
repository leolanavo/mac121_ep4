#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

node* Node_create (char* key) {
    node* new;
    new = malloc(sizeof(node));
    new->data.key = malloc(strlen(key));
    strcpy(new->data.key, key);
    new->data.info = 1;
    return (new);
}

void STableList_destroy (STableList* table) {
    node *nd, *aux;
    
    for (nd = table->head; nd != NULL; nd = aux) {
        aux = nd->next;
        free(nd->data.key);
        free(nd);
    }

    free(table);
}

STableList* STableList_simpleInsert (STableList* table, char* key) {
    node *nd, *prev;
    
    for (nd = table->head, prev = NULL; nd != NULL; prev = nd, nd = nd->next)
        if (strcmp(nd->data.key, key) == 0) {
            nd->data.info++;
            return (table);
        }

    nd = Node_create(key);

    if (prev == NULL) {
        table->count = 1;
        table->head = nd;
    }

    else {
        table->count++;
        prev->next = nd;
    }
    
    return(table);
}

STableList* STableList_orderInsert (STableList* table, char* key) {
    int cmp;
    node *nd, *prev, *new;
    
    for (nd = table->head, prev = NULL; nd != NULL && 
        (cmp = strcmp(nd->data.key, key)) <= 0; prev = nd, nd = nd->next)
        
            if (cmp == 0) {
                nd->data.info++;
                return (table);
            }

    table->count++;
    new = Node_create(key);
    
    if (prev == NULL) {
        if (nd != NULL)
            new->next = table->head;
        table->head = new;
    }
    
    else {
        prev->next = new;
        new->next = nd;
    }

    return (table);
}

void STableList_alphaPrint (STableList* table) {
    int i;
    node *nd, **adr;
    
    adr = malloc(table->count * sizeof(node*));
    for (i = 0, nd = table->head; i < table->count; nd = nd->next, i++) {
        adr[i] = nd;
    }
    
    qsort(adr, table->count, sizeof(node*), alphaCompareList);
    
    for (i = 0, nd = adr[i]; i < table->count; i++, nd = adr[i]) {
        printf("%s ", nd->data.key);
        printf("%d\n", nd->data.info);
    } 
}

void STableList_normalPrint (STableList* table) {
    node* nd;
    
    for (nd = table->head; nd != NULL; nd = nd->next) {
        printf("%s ", nd->data.key);
        printf("%d\n", nd->data.info);
    }
}

void STableList_numPrint (STableList* table) {
    int i;
    node *nd, **adr;
    
    adr = malloc(table->count * sizeof(node*));
    for (i = 0, nd = table->head; i < table->count; nd = nd->next, i++) {
        adr[i] = nd;
    }
    
    qsort(adr, table->count, sizeof(node*), numCompareList);
    
    for (i--, nd = adr[i]; i >= 0; i--, nd = adr[i]) {
        printf("%s ", nd->data.key);
        printf("%d\n", nd->data.info);
    } 
}
