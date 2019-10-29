#include <stdio.h>
#include <stdlib.h>
#include "stackLinkedList.h"

stackNode *pop(stackNode* root, int *retValue){
    // get and remove value from the list
    stackNode *iter = root;
    if ( !iter){
        // If given List Adress is Empty
        printf("Stack Node is Empty\n");
        return NULL;
    }
    if (!(iter -> next)){
        // If Stack List has only one Element
        *retValue = iter -> val;
        printf("value of %d is removed from list\n", *retValue);
        free(iter);
        printf("Now, Stack is Empty\n");
        return NULL;
    }
    // If Stack List has more than one Element
    while ( iter -> next -> next) // Find Last Element
        iter = iter -> next ; 
    *retValue = iter -> next -> val; // Send Value
    printf("value of %d is removed from list\n", iter -> next -> val);
    free(iter -> next); // Remove Element from the Stack List
    iter -> next = NULL; // Update Last Element tail
    return root;
}

stackNode* push(stackNode* root, int pushValue){
    // Send Value into the Stack List
    stackNode *iter = root;
    if (!iter){
        // If given List Adress is Empty
        printf("Stack Node is Empty\n");
        printf("Node is initializng...\n"); 
        iter = (stackNode*)malloc(sizeof(stackNode)); // Create New Node
        if (!iter){
            // If New Node couldn't be created
            printf("FAILED: There is no enough memory to create Node\n");
            return NULL;
        }
        // If Successfuly Created
        printf("Successfuly Created\n");
        iter -> val = pushValue;
        iter -> next = NULL;
        printf("value of %d is added to list\n", iter -> val);
        return iter;
    }
    // If Stack List already has an Element
    while (iter -> next) // Find Last Element
        iter = iter -> next;
    // Add New Element to end of Stack List
    iter -> next = (stackNode*)malloc(sizeof(stackNode));
    if (!iter){
        // If New Element couldn't be created
        printf("FAILED: There is no enough memory to create Node\n");
        return NULL;
    }
    // New Element Successfuly Created
    iter = iter -> next;
    iter -> val = pushValue;
    iter -> next = NULL;
    printf("value of %d is added to list\n", iter -> val);
    return root;
}

void printList(stackNode* root){
    // Print Stack List
    stackNode *iter = root;
    if ( !iter){
        // If given List Adress is Empty
        printf("Stack Node is Empty\n");
        return;
    }
    while (iter -> next){
        // Go End of the Stack List
        printf("%d -> ", iter -> val );
        iter = iter -> next;
    }
    printf("%d\n", iter -> val );
    return;
}