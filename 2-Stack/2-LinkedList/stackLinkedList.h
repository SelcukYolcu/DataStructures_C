#ifndef stackLinkedList
#define stackLinkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val; // pushed value for the List
    struct node *next; // New element of List
}stackNode;

int retVal; // return value from pop()

stackNode* pop(stackNode* root, int *retValue);
stackNode* push(stackNode* root, int pushValue);
void printList(stackNode* root);

#endif