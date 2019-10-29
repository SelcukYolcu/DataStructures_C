#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int result;
void main ()
{
    // Test Init
    stack *stackNode1 = init();
    stack *stackNode2 = init();
    
    // Test Push
    for (int i=0; i<10; i++)
        push(stackNode1, i*10);
    push(stackNode1, -1);
    push(NULL, -1);
    
    // Test Pop
    for (int i=0; i<10; i++)
         pop(stackNode1);
    pop(stackNode1);
    pop(NULL);
    
    // Test Push and Pop
    for (int i=0; i<10; i++) // fill stackNode1
        push(stackNode1, i*10);
    for (int i=0; i<10; i++)// Move stackNode1 to stackNode2
         push(stackNode2, pop(stackNode1));
    
    for (int i=0; i<9; i++)
        pop(stackNode2);
    print(stackNode2);
    for (int i=0; i<10; i++)
       if (push(stackNode1, pop(stackNode2))  == -1)
            break;
    print(stackNode1);
    
    // Test Print
    for (int i=0; i<10; i++)
        push(stackNode1, i*10);
    print(stackNode1);
    
    pop(stackNode2);
    print(stackNode2);
    print(NULL);
}
