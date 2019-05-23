#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

int printNode(node* root){
    // Print all List index by index
    node *iter = root;
    if (!iter){
        printf("Given root adress is NULL\n");
        return -1;
    }
    printf("Linked List Printing... :\n");
    while(iter->next != NULL){
        printf("%d -> ", iter -> val);
        iter = iter -> next;
    }
    printf("%d...\n", iter -> val);
    return 0;
}

node* createList(unsigned int size){
    // Create New Linked List of Specified Size
    node* root = (node*)malloc(sizeof(node));
    node* iter = root;
    int val = 0; // to set Node value
    iter -> val = ++val * 10; // value is according to preference
    iter -> next = NULL;
    while(--size){
        iter -> next = (node*)malloc(sizeof(node));
        iter  = iter -> next;
        iter -> val = ++val * 10; // value is according to preference
        iter -> next = NULL;
    }
    printf("New Created ");
    printNode(root);
    return root;
}

node* append(node* root, int val){
    // append value to the end of list
    node* iter= root;
    if (!iter){
        // if given root is NULL, crewate new list
        printf("Given root adress is NULL\n");
        printf("New List is creating ...\n");
        iter = (node*)malloc(sizeof(node));
        iter -> val = val; 
        iter -> next = NULL;
        root = iter;
        printf("New Created ");
	printNode(root);
        return root;

    }
    while(iter->next != NULL)
        iter=iter->next; // go end of the list
    // add the end of the list 
    iter->next = (node*)malloc(sizeof(node));
    iter = iter->next;
    iter-> val = val;
    iter-> next = NULL;
    printf("%d has been added to the end of list\n", val);
    printNode(root);
    return root;
}


node* extendList(node* root, unsigned int size){
    // Add the Specified Number of Nodes at the End of the List
    node* iter= root;
    int val = 0; // to set Node value
    if (!iter){
        // if given root is NULL, crewate new list
        printf("Given root adress is NULL\n");
        printf("New List is creating ...\n");
        iter = (node*)malloc(sizeof(node));
        iter -> val = ++val; // value is according to preference 
        iter -> next = NULL;
        root = iter;
        size--;
        printf("New Created ");
    }
    while(iter->next != NULL)
        iter=iter->next; // go end of the list
    while(size--){ 
        // add the end of the list 
        iter->next = (node*)malloc(sizeof(node));
        iter = iter->next;
        iter-> val = ++val; // value is according to preference 
        iter-> next = NULL;
    }
    printf("The list has been extended from the end\n");
    printNode(root);
    return root;
}

node* insertSequentially(node* root, int val){
    //insert value into List as sequentially
    node* iter = root;
    node* temp;
    
    if(!iter){
        // if given root is NULL, crewate new list
        printf("Given root adress is NULL\n");
        iter = (node *)malloc(sizeof(node));
        iter -> val = val;
        iter -> next = NULL;
        printf("New List has been created\n");
        return iter;
    }
    else if(val < iter -> val){
        // check first index of list to add
        temp = (node*)malloc(sizeof(node));
        temp -> next = iter;
        temp -> val = val;
        printf("%d has been added to head of list", val);
        return temp;
    }
    else{
        // find index to add
        while((iter -> next) && (val > (iter -> next -> val)))
            //add if next is null or bigger
            iter = iter -> next;
        temp = (node *)malloc(sizeof(node));
        temp -> val = val;
        temp -> next = iter -> next;
        iter -> next = temp;
        printf("%d has been added into list\n", val);
        // rot is has not been changed
        return root;
    }
}

node* deleteVal(node* root, int val){
    // delete vlaue from the list
    node* iter = root;
    node* temp;
    
    if(!iter){
        printf("Error: The root adres is NULL for value of %d\n", val);
        return iter;
    }
    else if(iter -> val == val){
        // check first index of list
        temp = iter;
        iter = iter -> next;
        free(temp);
        printf("%d is deleted from the head of list\n", val);
        return iter;
    }
    else{
        while((iter -> next) && (iter -> next -> val != val))
            iter = iter -> next;
        if(!(iter -> next))
            printf("%d did not be found in list\n", val);
        else{
            temp=iter -> next;
            iter -> next = iter -> next -> next;
            free(temp);
            printf("%d is deleted from the list\n", val);
        }
        return root;
    }
}
