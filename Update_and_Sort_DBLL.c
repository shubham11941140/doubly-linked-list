/* Program to Insert an element in a Sorted Doubly Linked list and then print the link list in a sorted manner */

/* We are keeping in mind that we are not optimising any approach and will use the knowledge of Basic pointers */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{ 
    int x; 	
    struct Node* next; 		// Pointer to next node in dBll
    struct Node* prev; 		// Pointer to previous node in dBLL 
}dBll;

void sortedInsert(dBll** headref, dBll* newNode) 
{ 
    dBll *current; 

    /* This if else decision making decides that at which position the newNode is inserted to giv a sorted list */
    
    // if list is empty insertion at first position
    if (*headref == NULL) 
    {
        *headref = newNode; 
    }

    // if the node is to be inserted at the beginning of the doubly linked list 
    else if ((*headref)->x >= newNode->x) 
    { 
        newNode->next = *headref; 
        newNode->next->prev = newNode; 
        *headref = newNode; 
    } 
  
    else 
    { 
        current = *headref; 
  
        // locate the node after which the new node is to be inserted 
        while (current->next != NULL && current->next->x < newNode->x) 
        {
            current = current->next; 
        }
              
        /* Making the appropriate links */
        newNode->next = current->next; 
  
        // if the new node is not inserted at the end of the list 
	    // This checks all the elements and if it is still not inserted itis inserted in the last
        if (current->next != NULL) 
	    {
            newNode->next->prev = newNode; 
	    }
  
        current->next = newNode; 
        newNode->prev = current; 
    } 
} 

/* It is not mentioned in the question to print the dBll but this is a function which will print the dBll */
void printdBll(dBll *head) 
{ 
    while (head != NULL) 
    { 
       	printf("%d ",head->x);
        head = head->next; 
    } 
} 

/* Main to run the program */
int main()
{
	int n,p,q;
	int list_size, i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter your elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	/* start with empty linked list */
	dBll *start = NULL;
	dBll *temp;

	printf("Enter the extra element: ");
	scanf("%d",&p);
	printf("Enter the element you want to replace: ");
	scanf("%d",&q);
	for(i=0;i<n;i++)
	{
		if(arr[i]==q)
		{
			arr[i]=p;   //replacing that position in the array with the updated value
		}
	}

	/* Create linked list from the array arr[n].*/
	for (i = 0; i< n; i++)
	{
		temp = (dBll *)malloc(sizeof(dBll));
		temp ->x = arr[i];
		sortedInsert(&start, temp);
	}

	printdBll(start);
	return 0;
}
