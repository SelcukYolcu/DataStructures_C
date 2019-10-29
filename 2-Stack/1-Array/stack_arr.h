#ifndef stack_arr
#define stack_arr
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int peak; // Number of Elements in Array
    int size; // Size of Array
    int *array;
} stack;

void print (stack *list);
stack* init(void);
int pop (stack *list);
int push (stack *list, int val);

#endif