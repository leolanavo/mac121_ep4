#ifndef TYPES_H
#define TYPES_H

/* The struct that will be used in all
 * of symbol tables, it associates a
 * char pointer and an integer.*/
typedef struct {
	char* key;
	int info;
} Entry;

/* The struct has a vector of Entries,
 * the maximum size of the vector and
 * and the number of different words
 * that are in the vector. */
typedef struct {
	Entry* data;
	int size;
	int count;
} STableVec;

/* The struct contains an Entry field,
 * and a pointer to the next node in
 * the linked list. */
typedef struct cell {
	Entry data;
	struct cell* next;
} node;

/* The struct contains a node pointer,
 * which will be the head of the linked
 * list, and a integer, which will count
 * how many different words that are
 * in the linked list. */
typedef struct {
    node* head;
    int count;
} STableList;

/* The struct contains an Entry field,
 * and two pointers to the right and
 * left node of the binary tree. */
typedef struct cellBT {
	Entry data;
	struct cellBT* right;
	struct cellBT* left;
} nodeBT;

/* The struct contains a node pointer,
 * which will be the head of the root, 
 * and a integer, which will count
 * how many different words that are
 * in the binary tree. */
typedef struct {
	nodeBT* root;
	int count;
} STableBT;

#endif
