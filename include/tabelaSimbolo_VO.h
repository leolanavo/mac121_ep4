#ifndef TABELASIMBOLO_VO_H
#define TABELASIMBOLO_VO_H

#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stableVec.h"
#include "../include/auxFunctions.h"
#include "../include/readWord.h"
#include "../include/types.h"

/* Recieves a file pointer and a string. It reads the
 * text from the file and prints its words with the
 * corresponding frequencies according to the given
 * print mode. Uses a orderly vector as symbol table.*/
void orderVec(FILE* file, char* mode);

#endif
