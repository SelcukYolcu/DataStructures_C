#ifndef binarySearch
#define binarySearch

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bst{
    int val; // value of node
    // childs of node
    struct bst *rChild;
    struct bst *lChild;
}bst;

int delete(bst **node, int val);
int insert(bst **node, int val);
bool search(bst *node, int val);
int travel(bst *node);
int max(bst *node);
int min(bst *node);
void print2D(bst *root);

#endif