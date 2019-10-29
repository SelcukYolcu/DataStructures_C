#include <stdio.h>
#include <stdlib.h>
#include "stackLinkedList.h"

int main(int argc, char *argv[]){
    
    stackNode *root = NULL; // Create Stack Node
    
    root = pop(root, &retVal); // try to get value from empt list
    root = push (root, 15);    // add value to empty list. new list must be created
    printList(root); // Print list
    
    root = pop(root, &retVal); // get value from list which has just one value. list must be cleaned
    root = pop(root, &retVal); // try to get value from empty list
    printList(root); // try to print empty list
    
    for (int i=0; i < 10; i++) // create list from empty list 
        root = push(root, (i+1)*10);
        
    printList(root);          // print list
    
    for (int i=0; i <= 10; i++) // get value from the list 
        root = pop(root, &retVal); // this cycle is more than push cycle.
                                    // List must be cleaned at 9th index
                                    // list must be empty at end of cycle
}