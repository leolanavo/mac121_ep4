#ifndef TABELASIMBOLO_AB_H
#define TABELASIMBOLO_AB_H

#include <stdio.h>
#include <stdlib.h>
#include "../include/stableBT.h"
#include "../include/readWord.h"
#include "../include/types.h"

/* Receives a FILE pointer, and char pointer.
 * The file will be where the input text will come
 * from, and the mode is the way the symbol table
 * will be printed.*/
void binTree(FILE* file, char* mode);

#endif
