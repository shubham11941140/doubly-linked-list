/* Definition of a Node of a doubly linked list */

typedef struct Node 
{ 
    Element_type element; 	// in this case taken as (int data)
    struct Node* next; 		// Pointer to next node in dBll
    struct Node* prev; 		// Pointer to previous node in dBLL 
}dBll; // completely replaced the value of struct node to a new Abstract Data Type(ADT) dBll for further use in the program

/* Only code snippet has been mentioned here as we do not require to write the full code */
