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
    
    STable* stable = STable_create(1024);
    end = 0;
    while (end == 0) {
        str = readWord(file, &end);
        STable_simpleInsert(stable, str);
    }

    if ((strcmp(mode, "A")) == 0) {
        qsort(stable->data, stable->count, sizeof(Entry), alphaCompare);
        STable_printOrder(stable);
    }
    
    else {
        qsort(stable->data, stable->count, sizeof(Entry), numCompare);
        STable_printReverse(stable);
    }
    STable_destroy(stable);
    return;
}
