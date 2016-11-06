#include <stdlib.h>
#include <string.h>
#include "../include/stableList.h"
#include "../include/auxFunctions.h"
#include "../include/readWord.h"
#include "../include/types.h"

void orderList(FILE* file, char* mode) {
    int end;
    char* str;
    
    STableList* stable = malloc(sizeof(STableList));
    stable->head = NULL;
    stable->count = 0;
    
    end = 0;
    while (end == 0) {
        str = readWord(file, &end);
        stable = STableList_orderInsert(stable, str);
    }

    if ((strcmp(mode, "O")) == 0) {
        STableList_numPrint(stable);
    }

    else
        STableList_normalPrint(stable);

    STableList_destroy(stable);

    return;
}
