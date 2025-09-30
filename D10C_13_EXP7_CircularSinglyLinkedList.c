#include <stdio.h>
#include <stdlib.h>

// Standard node structure for a singly linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the end. We keep track of the 'tail' for efficiency.
struct Node* insertEnd(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (tail == NULL) { // If the list is empty...
        newNode->next = newNode; // ...the new node points to itself to form the circle.
        tail = newNode;
    } else { // If the list is not empty...
        newNode->next = tail->next; // The new node's 'next' must point to the head.
        tail->next = newNode;       // The old tail's 'next' must point to the new node.
        tail = newNode;             // The new node becomes the new tail.
    }
    printf("%d inserted\n", value);
    return tail; // Return the updated tail pointer.
}

// Function to display the circular list.
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail->next; // To start traversal, we begin at the head.
    printf("Circular Linked List: ");
    // A do-while loop is perfect for circular lists because we need the loop to run at least once.
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next); // The loop stops when we've circled back to the head.
    printf("\n");
}

// Function to delete the first node (the head).
struct Node* deleteFirst(struct Node* tail) {
    if (tail == NULL) { // Check for an empty list.
        printf("List is empty\n");
        return NULL;
    }
    struct Node* head = tail->next; // The node to be deleted is the head.
    if (head == tail) { // If there's only one node in the list...
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL; // ...the list becomes empty.
    }
    tail->next = head->next; // The tail must now point to the new head (the second node).
    printf("Deleted: %d\n", head->data);
    free(head); // Free the memory of the old head.
    return tail;
}

int main() {
    struct Node* tail = NULL;
    int value = 13;

    // Insert 5 nodes.
    for (int i = 0; i < 5; i++) {
        tail = insertEnd(tail, value);
        value += 13;
    }

    display(tail);

    // Delete the first two nodes.
    printf("\nDeleting two nodes...\n");
    tail = deleteFirst(tail);
    tail = deleteFirst(tail);

    display(tail);

    return 0;
}
