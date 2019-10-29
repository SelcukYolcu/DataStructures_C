#ifndef  QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int val; // value of node
    struct n *next; // next node of current node
    struct n *prev; // previous node of current node
}node;

int enqueue(node** queue, int val);
int dequeue(node** queue);
int printNode(node* root);

#endif