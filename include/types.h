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
} STableVec;

typedef struct cell {
	Entry data;
	struct cell* next;
} node;

typedef struct {
    node* head;
    int count;
} STableList;

typedef struct cellBT {
	Entry data;
	struct cellBT* right;
	struct cellBT* left;
} nodeBT;

typedef struct {
	nodeBT* root;
	int count;
} STableBT;

#endif
