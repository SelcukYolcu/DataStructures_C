#ifndef CircularLinkedList
#define CircularLinkedList
#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    int val;
    struct n* next;
}node;

int printNode(node* const root);
node* createList(unsigned int size);
node* append(node* root, int val);
node* extendList(node* root, unsigned int size);
node* insertSequentially(node* root, int val);
node* deleteVal(node* root, int val);
node* deleteAll(node* root);

#endif
