#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node* Node_create () {
    node* new;
    new = malloc(sizeof(node));
    new->data.key = NULL;
    new->data.info = 0;
}

node* Node_destroy (node* nd) {
    free(nd->data.key);
    free(nd);
}

node* Node_insertSimple (node* head, char* key) {
    node* nd, prev;
    
    for (nd = head, prev = NULL; nd != NULL; prev = nd, nd = nd->next)
        if (strcmp(nd->data.key, key) == 0)
            nd->data.info++;

    
}
