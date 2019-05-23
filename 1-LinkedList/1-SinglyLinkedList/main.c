#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

int main()
{
    // Test Methods
    node *root = createList(5);
    root = extendList(root, 3);
    root = extendList(NULL, 3);
    
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
    deleteVal(NULL, 4);

    root = append(root, 10);
}




