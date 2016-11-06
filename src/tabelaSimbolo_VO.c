#include <stdlib.h>
#include <string.h>
#include "../include/stableVec.h"
#include "../include/auxFunctions.h"
#include "../include/readWord.h"
#include "../include/types.h"

void orderVec(FILE* file, char* mode) {
    int end;
    char* str;
    
    STableVec* stable = STableVec_create(1024);
    end = 0;
    while (end == 0) {
        str = readWord(file, &end);
        STableVec_orderInsert(stable, str);
    }

    if ((strcmp(mode, "O")) == 0) {
        qsort(stable->data, stable->count, sizeof(Entry), numCompare);
        STableVec_reversePrint(stable);
    }
    else
        STableVec_print(stable);

    STableVec_destroy(stable);

    return;
}
