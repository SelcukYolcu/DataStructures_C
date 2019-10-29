#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void main(int argc, char *argv[]){
    
    node *root=NULL;
    // Enqueue into the Que List
    for(int i = 0; i<10; i++)
        enqueue(&root, i*10);
    printNode(root); // Print Que
    
    // Dequeue from the Que List more than Enqueue
    for(int i = 0; i<11; i++)
        dequeue(&root);
        
    // Print an empty Que
    printNode(root);

}
