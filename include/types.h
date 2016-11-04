#ifndef TYPES_H
#define TYPES_H

typedef struct {
	char* key;
	int info;
} Entry;

typedef struct {
	Entry* data;
	int size;
	int count;
} STable;

typedef struct cell{
	Entry data;
	struct cell* next;
} node;

#endif
