#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "binarySearch.h"

int minVal = 0, maxVal = 0;
int main(int argc, char* argv[]){
    srand(time(0));
    // initialize the root of tree
    bst *root = NULL;
    
    // test Insert
    printf("\n\nTest Insert\n");
    for (int i=0; i <10; i++){
        insert(&root, rand() % 100);
        NULL;
    }
    
    // test Min and Max
    printf("\n\nTest Min and Max\n");
    maxVal = max(root);
    printf("Max Value of tree is %d \n", maxVal);
    minVal = min(root);
    printf("Min Value of tree is %d \n", minVal);
    max(NULL);
    min(NULL);
    
    // test Search
    printf("\n\nTest Search\n");
    search(root, minVal);
    search(root, maxVal);
    search(root, 101);
    
    // test Travel
    printf("\n\nTest Travel\n");
    travel(root);
    
    // test Delete
    printf("\n\nTest Delete\n");
    delete(&root, minVal);
    delete(&root, maxVal);
    
    // Graph Tree
    print2D(root);

}

