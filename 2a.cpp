#include <stdio.h>
#include<stdlib.h>
// Linked List Node
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
 
// Function to traverse the linked list
void traverse()
{
    struct node* temp;
 
    // List is empty
    if (start == NULL)
        printf("\nList is empty\n");
 
    // Else print the LL
    else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n",
                   temp->info);
            temp = temp->link;
        }
    }
}
 
// Function to insert at the front
// of the linked list
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;
 
    // Pointer of temp will be
    // assigned to start
    temp->link = start;
    start = temp;
}
 
// Function to insert at the end of
// the linked list
void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
 
    // Enter the number
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
 
    // Changes links
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
 

 
// Function to delete from the front
// of the linked list
void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}
 
// Function to delete from the end
// of the linked list
void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}
 

 

 

 
// Driver Code
int main()
{
    int choice;
    while (1) {
 
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at"
               " starting\n");
        printf("\t3  For insertion at"
               " end\n");
        
        printf("\t4 For deletion of "
               "first element\n");
        printf("\t5  For deletion of "
               "last element\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteEnd();
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}