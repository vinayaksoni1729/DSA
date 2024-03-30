#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of Circular LL
void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;

    struct Node* temp = *head_ref;

    // If the list is not empty, find the last node and update its next
    if (*head_ref != NULL) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // For the first node
    else {
        new_node->next = new_node;
    }

    *head_ref = new_node;
}

// Function to print nodes in the Circular Linked List
void printList(struct Node* head) {
    struct Node* temp = head;

    if (head != NULL) {
        do {
            // Print the data
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

// Driver Code
int main() {
    // Initialize list as empty
    struct Node* head = NULL;

    // Created linked list will be 11->2->56->12
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printf("Contents of Circular Linked List\n");

    // Function call to print the list
    printList(head);

    return 0;
}
