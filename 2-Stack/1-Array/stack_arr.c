#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

stack* init(void){
    // Initialize Stack structure for first using
    stack *list = (stack *)malloc(sizeof(stack)); // Create a Stack
    if (!list){
        // Check temp is created
        printf ("There is no enough space on memory to Initialize Stack\n");
        return NULL;
    }
    list -> peak = 0; // Show How many elemnts in List
    list -> size = 2; // Show Current Limit of List Size
    list -> array = (int*)malloc(sizeof(int) * (list->size)); // Stack List Elemnts
    if (!list -> array){
        // Check temp is created
        printf ("There is no enough space on memory to Initialize Stack List\n");
        return NULL;
    }
    printf("New Stack Node is succesfully created\n");
    return list; // Return Pointer of Stack
}

int push (stack *list, int val){
    // Push Data into Stack List
    if (!list){
        // Check Stack adress availability
        printf("Push: Stack adress is NULL, give an available adress for %d\n", val);
        return -1;
    }
    if (val <= -1){
        // Check Data Value
        printf("Push: Value Error\n");
        return -1;
    }
    if (list -> peak >= list -> size){
        // Check Whether Size is Enough to Locate Data
        int *temp = (int *) malloc (sizeof (int) * list -> size * 2); // Crate New Doubled Area
        if (!temp){
            // Check temp is created
            printf ("There is no enough space on memory to locate %d\n", val);
            return -1;
	    }
        for (int i = 0; i < list -> size; i++) // Copy Old Array to New
    	    temp[i] = list -> array[i];
        list -> size *= 2; // Update Size
        free (list -> array); // Free Old Array pointer
        list -> array = temp; // Update Stack Array Pointer for New Array
    }
    list -> array[(list -> peak)++] = val; // Push Data and Update Peak
    printf("Push: %d is pushed into the Stack List\n", val);
    return val;
}

int pop (stack *list){
    if (!list){
        // Check Stack adress availability
        printf("Pop: Stack adress is NULL, give an available adress \n");
        return -1;
    }
    if(list->array == NULL || list->peak == 0){
        // Check Stack Array is Empty
        printf("Pop: Stack array is empty \n");
        return -1;
    }
    // If Stack Array is not Empty
    (list -> peak)--; // Decrease Peak
    if ((list->peak <= (int)(list -> size)/4) && (list->size > 2)){
        // If Array is mainly Empty, Decrease Size of Array
        int *temp = (int *) malloc (sizeof (int) * ((list -> size) / 2)); 
        // Create New Area as half of Current Array
        for (int i = 0; i < ((list -> size) / 2); i++) // Copy Old Array to New
            temp[i] = list -> array[i]; 
        list -> size /= 2; // Update Size
        free (list -> array); // Free Old Array Pointer
        list -> array = temp; // Update Stack Array
    }
    printf ("pop: array[%d] = %d is removed \n", 
            list -> peak, 
            list -> array[list -> peak]
    );
    return list -> array[list -> peak]; // Pop Data
}

void print (stack *list){
    // Print Stack List
    if (!list){
        // Check Stack adress availability
        printf("Print: Stack adress is NULL, give an available adress\n");
        return;
    }
    printf ("\nsize = %d\n", list -> size);
    if(!list -> peak) 
        printf("Print: Stack array is empty \n");
    for (int i = 0; i < list -> peak; i++)
        printf ("array[%d] = %d\n", i, list -> array[i]);
    printf ("\n");
}
