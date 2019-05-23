#include <stdlib.h>
#include <stdio.h>
#include "CircularLinkedList.h"

int main()
{
    //test methods
    
    node* root = createList(3);
    extendList(root, 3);
    
    root=deleteAll(root);
    
    root = insertSequentially(root, 400);
    root = insertSequentially(root, 40);
    root = insertSequentially(root, 4);
    root = insertSequentially(root, 450);
    root = insertSequentially(root, 50);
    
    printNode(root);
    
    root = deleteVal(root, 50);
    root = deleteVal(root, 55);
    root = deleteVal(root, 4);
    root = deleteVal(root, 450);
    
    printNode(root);
    
    root=deleteAll(root);
    
    root = append(root, 20);
    root = append(root, 40);
    
    root = deleteAll(root);
    
    root = extendList(root, 1);
    root = extendList(root, 3);
    return 0;
}

