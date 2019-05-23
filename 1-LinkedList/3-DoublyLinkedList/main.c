#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"

int main()
{    
    //test CreateList and printNode, printReversedNode
    node* root= createList(5);
    printNode(root);
    printReversedNode(root);
    root = deleteAll(root);
    
    //test append
    for (int i = 1; i<=5; i++)
        root = append(root, i*100);
    printReversedNode(root);

    //test deleteAll
    deleteAll(NULL);
    root = deleteAll(root);
    printNode(root);

    //test extendList
    root = extendList(root, 5);
    root = extendList(root, 1);
    printReversedNode(root);
    root = deleteAll(root);

    //test insertSequentially
    for (int i = 10; i <= 30; i = i + 10)
        root = insertSequentially(root, i);  
    for (int i = 5; i <= 35; i = i + 10)
        root = insertSequentially(root, i);  
    root = insertSequentially(root, 10);
    printNode(root);
    printReversedNode(root);

    //test deleteVal
    root = deleteVal(root, 10);
    root = deleteVal(root, 5);
    root = deleteVal(root, 35);
    printNode(root);
    printReversedNode(root);
    root = deleteAll(root);

    return 0;
}





