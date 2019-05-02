#ifndef SinglyLinkedList
#define SinglyLinkedList

#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    int val;
    struct n* next;
}node;

int printNode(node *root);
node* createList(int size);
node* append(node* root, int val);
node* extendList(node* root, int size);
node* insertSequentially(node* root, int val);
node* deleteVal(node* root, int val);

#endif