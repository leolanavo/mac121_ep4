#include <stdlib.h>
#include <string.h>
#include "../include/stableVec.h"
#include "../include/auxFunctions.h"
#include "../include/readWord.h"
#include "../include/types.h"

void orderVec(FILE* file, char* mode) {
    int end;
    char* str;
    
    STable* stable = STable_create(1024);
    end = 0;
    while (end == 0) {
        str = readWord(file, &end);
        STable_orderInsert(stable, str);
    }

    if ((strcmp(mode, "O")) == 0) {
        qsort(stable->data, stable->count, sizeof(Entry), numCompare);
        STable_printReverse (stable);
    }
    else
        STable_printOrder(stable);

    return;
}
