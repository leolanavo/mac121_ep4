#include <stdlib.h>
#include <string.h>
#include "../include/stableVec.h"
#include "../include/auxFunctions.h"
#include "../include/readWord.h"
#include "../include/types.h"

/* Recieves a file pointer and a string. It reads the
 * text from the file and prints its words with the
 * corresponding frequencies according to the given
 * print mode. */
void desorderVec(FILE* file, char* mode) {
    int end;
    char* str;
    
    STableVec* stable = STableVec_create(1024);
    end = 0;
    while (end == 0) {
        str = readWord(file, &end);
        STableVec_simpleInsert(stable, str);
    }

    if ((strcmp(mode, "A")) == 0) {
        qsort(stable->data, stable->count, sizeof(Entry), alphaCompare);
        STableVec_print(stable);
    }
    
    else {
        qsort(stable->data, stable->count, sizeof(Entry), numCompare);
        STableVec_reversePrint(stable);
    }

    STableVec_destroy(stable);
    
    return;
}
