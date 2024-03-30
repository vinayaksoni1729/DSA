#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the content of
// linked list starting from the
// given node
void printList(struct Node* n)
{
    // Iterate till n reaches NULL
    while (n != NULL) {
        // Print the data
        printf("%d ", n->data);
        n = n->next;
    }
}

// Driver Code
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data in the first node
    head->data = 1;

    // Link the first node with the second
    head->next = second;

    // Assign data to the second node
    second->data = 2;
    second->next = third;

    // Assign data to the third node
    third->data = 3;
    third->next = NULL;

    printList(head);

    return 0;
}