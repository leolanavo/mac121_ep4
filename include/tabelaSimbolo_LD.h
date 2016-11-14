#ifndef TABELASIMBOLO_LD_H
#define TABELASIMBOLO_LD_H

#include <stdlib.h>
#include <string.h>
#include "../include/stableList.h"
#include "../include/auxFunctions.h"
#include "../include/readWord.h"
#include "../include/types.h"

/* Receives a FILE pointer, and char pointer.
 * The file will be where the input text will come
 * from, and the mode is the way the symbol table
 * will be printed.*/
void desorderList(FILE* file, char* mode);
#endif
