#ifndef READWORD_H
#define READWORD_H

#include <stdio.h>

/* Recieve a pointer a file from where it will read a word,
 * and return the read word in lower case. It also recieves
 * an integer pointer so it can return 1 when the EOF is reached
 * end, will be 0, otherwise. */
char* readWord(FILE* file, int* end);

#endif
