#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/auxFunctions.h"

nodeBT* NodeBT_create (char* key) {
    nodeBT* new;
    new = malloc(sizeof(nodeBT));
    new->data.key = malloc(strlen(key));
    strcpy(new->data.key, key);
    new->right = new->left = NULL;
    new->data.info = 1;
    return (new);
}

void NodeBT_destroy (nodeBT* root) {
    
    if (root == NULL) return;
    
    if (root->left == NULL && root->right == NULL) {
        free(root->data.key);
        free(root);
        return;
    }

    NodeBT_destroy (root->left);
    NodeBT_destroy (root->right);
}

nodeBT* NodeBT_search (nodeBT* root, char* key) {
    int cmp;
    nodeBT* nd;

    for (nd = root; nd != NULL; cmp = strcmp(nd->data.key, key)) {
        if (cmp == 0) break;
        if (cmp > 0) nd = nd->left;
        else nd = nd->right;
    }

    return (nd);
}

STableBT* STableBT_insert (STableBT* table, char* key) {
    int cmp;
    nodeBT *nd, *prev, *new;
    
    for (nd = table->root, prev = NULL; nd != NULL;) {

        prev = nd;
        cmp = strcmp(nd->data.key, key);
        
        if (cmp == 0) {
            nd->data.info++;
            return (table);
        }
        
        if (cmp > 0)
            nd = nd->left;
        
        else 
            nd = nd->right;
    }
    
    new = NodeBT_create(key);
    
    if (prev == NULL) {
        table->root = new;
    }
    
    else if (cmp < 0) prev->right = new;
    
    else prev->left = new;

    table->count++;
    
    return (table);
}

nodeBT* NodeBT_remove (nodeBT* root, char* key) {
    int cmp;
    nodeBT* aux;
    
    if (root == NULL) return root;
    cmp = strcmp(root->data.key, key);
    
    if (cmp == 0) {
        if (root->left == NULL) {
            aux = root->right;
            free(root->data.key);
            free(root);
            root = aux;
            return (root);
        }

        if (root->right == NULL) {
            aux = root->left;
            free(root->data.key);
            free(root);
            root = aux;
            return (root);
        }

        for (aux = root->left; aux != NULL && aux->right != NULL; 
            aux = aux->right);

        free(root->data.key);
        root->data.key = malloc(strlen(aux->data.key));
        strcpy(root->data.key, aux->data.key);
        root->data.info = aux->data.info;
        root->left = NodeBT_remove(root->left, aux->data.key);
        return (root);
    }

    if (cmp > 0) root->left = NodeBT_remove(root->left, key);
    else root->right = NodeBT_remove(root->right, key);
    return(root);
}

void NodeBT_print (nodeBT* root) {
    
    if (root->left == NULL) {
        printf("%s ", root->data.key);
        printf("%d\n", root->data.info);
        return;
    }
    NodeBT_print(root->left);
    printf("%s ", root->data.key);
    printf("%d\n", root->data.info);
    if (root->right != NULL) NodeBT_print(root->right);
}

void genVector (nodeBT** v, nodeBT* root, int* index) {
    if (root == NULL) return;
    v[(*index)] = root;
    
    if (root->left != NULL) {
        *index = (*index) + 1;
        genVector(v, root->left, index);
    }

    if (root->right != NULL) {
        *index = (*index) + 1;
        genVector(v, root->right, index);
    }
}

void STableBT_numPrint (STableBT* table) {
    int index, i;
    nodeBT **adr, *nd;
    
    index = 0;
    adr = malloc(table->count * sizeof(node*));
    genVector(adr, table->root, &index);

    qsort(adr, table->count, sizeof(nodeBT*), numCompareBT);

    for (i = table->count - 1, nd = adr[i]; i >= 0; i--, nd = adr[i]) {
        printf("%s ", nd->data.key);
        printf("%d\n", nd->data.info);
    } 
}