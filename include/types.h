#ifndef TYPES_H
#define TYPES_H

typedef struct {
	char* key;
	int info;
} Entry;

typedef struct {
	Entry* data;
	int size;
	int ind;
} STable;

typedef struct node{
	Entry* data;
	struct node* next;
} cell;

#endif