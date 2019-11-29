#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarySearch.h"

#define COUNT 10

int deleteUtil(bst **node, int val){
    // Delete value from tree
    bst **root = node; // pointer of node pointer
    bst *iter = *node; // root pointer
    bst *temp = *node; // root pointer
    if(!iter){
        // If Node i NULL
        printf("%d couldn't be found in tree\n", val);
        return -1;
    }
    if(iter -> val == val){
        // Value is found
        if(!(iter -> rChild) && !(iter -> lChild)){
            // If node has not any child
            *root = NULL;
            free(iter);
            return 0;
        }
        // either
        else if(iter -> rChild){
            // Node has right child
            // Replace with min of right
            iter -> val = min(iter -> rChild);
            // Delete original min of right
            return deleteUtil(&(iter -> rChild), iter -> val);
        }
        // or
        else if(iter -> lChild){
            // Node has left child
            // Replace with max of left
            iter -> val = max(iter -> lChild);
            // Delete original max of left
            return deleteUtil(&(iter -> lChild), iter -> val);
        }
    }
    if(val < iter -> val)
        // if value is lower, Go to left tree
        return deleteUtil(&(iter -> lChild), val);
    else if(val > iter -> val)
        // if value is gihher, Go to right tree
        return deleteUtil(&(iter -> rChild), val);
    return 0;
}

int delete(bst **node, int val){
    // This method is to call deleteUtil
    if (deleteUtil(node, val) >= 0){
        // If success
        printf("%d is deleted from tree \n", val);
        return 0;
    }
    return -1;
}

int insert(bst **node, int val){
    // Insert value into tree
    bst **root = node; // pointer of node pointer
    bst *iter = *node; // root pointer
    bst *temp = *node; // root pointer
    if (!iter){
        // If the Node is NULL, then Create new one
        iter = (bst*)malloc(sizeof(bst));
        if(!iter){
            // If It fails
            printf("Memory error to create root\n");
            return -1;
        }
        // If It is successfully created, then initialize
        iter -> val = val;
        iter -> rChild = NULL;
        iter -> lChild = NULL;
        *root = iter;
        printf("%d is added into tree\n", iter -> val);
        return 0;
    }
    // If tree has nodes, then find correct locate
    if (val >= iter -> val)
        return insert(&(iter -> rChild), val);
    else
        return insert(&(iter -> lChild), val);
}

bool search(bst *node, int val){
    // Search value in the tree
    bst *iter = node; // pointer of Node
    if(!iter){
        // If Node is NULL
        printf("%d couldn't find in tree\n", val);
        return false;
    }
    if(iter -> val == val){
        // If value is found in tree
        printf("%d is in tree\n", iter -> val);
        return true;
    }
    else if (val > iter -> val)
        // If value is higher, Check right tree
        return search(iter -> rChild, val);
    else if (val < iter -> val)
        // If value is lower, Check left tree
        return search(iter -> lChild, val);
}

int travel(bst *node){
    // To show all of node values
    bst *iter = node; // Node pointer
    if (!iter)
        // If Node is NULL
        return 0;
    // BGo to Min Node 
    // Travel Sequentially
    travel(iter -> lChild);
    printf("%d --> ", iter -> val);
    travel(iter -> rChild);
}

int max(bst *node){
    // Find Max of Tree
    bst *iter = node;
    if (!iter){
        // Check Adress is  available
        printf("Error: Root adress is NULL\n");
        return -1;
    }
    // Go to rightmost node
    while ((iter -> rChild))
        iter = iter -> rChild;
    return iter -> val;
}

int min(bst *node){
    // Find Min of Tree
    bst *iter = node;
    if (!iter){
        // Check Adress is  available
        printf("Error: Root adress is NULL\n");
        return -1;
    }
    // Go to leftmost Node
    while ((iter -> lChild))
        iter = iter -> lChild;
    return iter -> val;
}

/*##############################################################*/
/*                       Garph of Tree                          */
/*              Below of this part is taken from                */
/* https://www.geeksforgeeks.org/print-binary-tree-2-dimensions */
/*##############################################################*/

void print2DUtil(bst *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->rChild, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->val); 
  
    // Process left child 
    print2DUtil(root->lChild, space); 
} 

// Wrapper over print2DUtil() 
void print2D(bst *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
}
