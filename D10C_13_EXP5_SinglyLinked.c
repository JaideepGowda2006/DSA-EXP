#include <stdio.h>
#include <stdlib.h> // For memory allocation functions like malloc() and free().

// Node structure
struct Node {
    int data; // To store the integer value.
    struct Node* next; // A pointer to the next node in the list.
};

// Function to create a new node
struct Node* createNode(int value) {
    // Allocate memory for a new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; // Set the node's data.
    newNode->next = NULL; // The new node's 'next' pointer is initially NULL because it's the last node.
    return newNode; // Return the newly created node.
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head; // Start from the head of the list.
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) { // Traverse until the end of the list (where 'next' is NULL).
        printf("%d ", temp->data); // Print the data of the current node.
        temp = temp->next; // Move to the next node.
    }
    printf("\n");
}

// Function to insert node at the end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value); // Create the new node.
    if (head == NULL) {
        // If the list is empty, the new node becomes the head.
        return newNode;
    }
    struct Node* temp = head; // Start from the head.
    while (temp->next != NULL) // Traverse to the last node.
        temp = temp->next;
    temp->next = newNode; // Link the last node's 'next' pointer to the new node.
    return head; // Return the head of the list.
}

// Function to delete first node
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node* temp = head; // Temporarily store the current head.
    head = head->next; // Move the head pointer to the second node.
    printf("Deleted: %d\n", temp->data); // Print the data of the deleted node.
    free(temp); // Free the memory of the old head node to prevent memory leaks.
    return head; // Return the new head.
}

int main() {
    struct Node* head = NULL; // Initially, the list is empty, so head is NULL.
    int value = 13;

    // Insert 5 nodes (multiples of 13)
    for (int i = 0; i < 5; i++) {
        head = insertEnd(head, value);
        printf("%d inserted\n", value);
        value += 13;
    }

    display(head);

    // Delete first 2 nodes
    printf("\nDeleting two nodes...\n");
    head = deleteFirst(head);
    head = deleteFirst(head);

    display(head);

    return 0;
}
