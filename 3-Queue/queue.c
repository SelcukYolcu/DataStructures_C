#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int enqueue(node** queue, int val){
    // Add data to end of the Que List
    node **root = queue;
    node *iter = *root;
    node *temp;
    if (!iter){
        // If given adress is not available
        printf("Given root adress is NULL to add %d\n", val);
        iter = (node*)malloc(sizeof(node)); // Create New Que
        if (!iter){
            // If new Que List couldn't be created
            printf("Error: create new queue node\n");
            return -1;
        }
        printf("Node element is created\n");
        // If successfully created, add value and set pointers
        iter -> val = val;
        iter -> next = iter;
        iter -> prev = iter;
        printf("%d is added into root adress\n", iter -> val);
        *root = iter; 
        return iter -> val;
    }
    // Add data to end of Que List
    temp = iter -> prev; // Go end of Que List
    iter -> prev = (node*)malloc(sizeof(node)); // Create New Element
    if (!(iter -> prev)){
        // If new Que Element couldn't be created
        printf("Error: create new queue element\n");
        return -1;
    }
    // If successfully created
    // Update tails and value
    iter = iter -> prev;
    temp -> next = iter;
    iter -> val = val;
    iter -> next = *root;
    iter -> prev = temp;
    printf("%d is added into queue list\n", val);
    return iter -> val;
}

int dequeue(node** queue){
    // Get data form top of the Que List
    node **root = queue;
    node *iter = *root;
    int temp;
    if(!iter){
        // If given adress is not available
        printf("\nError: Given adress is NULL\n\n");
        return -1;
    }
    if(iter -> next == iter){
        // If Que has only one element
        printf("%d is single value of queue list\n", iter -> val);
        printf("Value removed from list\n");
        temp = iter -> val;
        free(iter);
        *root = NULL;
        printf("root is NULL \n");
        return temp;
    }
    // Update tails and Get Data
    iter -> prev -> next = iter -> next;
    iter -> next -> prev = iter -> prev;
    *root = iter -> next;
    temp = iter -> val;
    free(iter);
    printf("%d removed from list\n", temp);
    return temp;
}

int printNode(node* root){
    // Print Que List
    node *iter = root;
    if (!iter){
        // If given adress is not available
        printf("Given root adress is NULL\n");
        return -1;
    }
    while(iter->next != root){ // Go on Que List
        printf("%d -> ", iter -> val);
        iter = iter -> next;
    }
    printf("%d...\n", iter -> val);
    return 0;
}