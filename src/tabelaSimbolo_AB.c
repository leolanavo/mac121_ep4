#include <stdio.h>
#include <stdlib.h>
#include "../include/stableBT.h"
#include "../include/readWord.h"
#include "../include/types.h"

void binTree(FILE* file, char* mode) {
    int end;
    char* str;
    
    STableBT* stable = malloc(sizeof(STableBT));
    stable->root = NULL;
    stable->count = 0;
    
    end = 0;
    
    while (end == 0) {
        str = readWord(file, &end);
        stable = STableBT_insert(stable, str);
    }

    if ((strcmp(mode, "O")) == 0) {
        STableBT_numPrint(stable);
    }
    
    else
        NodeBT_print(stable->root);

    NodeBT_destroy(stable->root);
    free(stable);

    return;
}
