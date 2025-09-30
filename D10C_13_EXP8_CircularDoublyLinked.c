#include <stdio.h>
#include <stdlib.h>

// Node structure with both 'next' and 'prev' pointers.
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the end.
struct Node* insertEnd(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (tail == NULL) { // If the list is empty...
        newNode->next = newNode; // ...the node points to itself in both directions.
        newNode->prev = newNode;
        tail = newNode;
    } else {
        struct Node* head = tail->next; // Get the current head.
        newNode->next = head;         // New node's next points to head.
        newNode->prev = tail;         // New node's prev points to old tail.
        head->prev = newNode;         // Head's prev must now point to the new node.
        tail->next = newNode;         // Old tail's next must now point to the new node.
        tail = newNode;               // Update the tail pointer.
    }
    printf("%d inserted\n", value);
    return tail;
}

// Display the list from head to tail (forward).
void displayForward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail->next; // Start from the head.
    printf("CDLL Forward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next); // Loop until we circle back to the head.
    printf("\n");
}

// Display the list from tail to head (backward).
void displayBackward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail; // Start from the tail.
    printf("CDLL Backward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev; // Traverse using the 'prev' pointer.
    } while (temp != tail); // Loop until we circle back to the tail.
    // The loop condition stops one short, so we print the last element (which is the tail's data) outside the loop.
    printf("%d\n", temp->data);
}

// Delete the first node (the head).
struct Node* deleteFirst(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* head = tail->next;
    if (head == tail) { // If there is only one node...
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL; // ...the list becomes empty.
    }
    struct Node* newHead = head->next; // Find the node that will become the new head.
    tail->next = newHead;              // Link the tail to the new head.
    newHead->prev = tail;              // Link the new head back to the tail.
    printf("Deleted: %d\n", head->data);
    free(head);                        // Free the old head.
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

    displayForward(tail);
    displayBackward(tail);

    // Delete the first two nodes.
    printf("\nDeleting two nodes...\n");
    tail = deleteFirst(tail);
    tail = deleteFirst(tail);

    displayForward(tail);
    displayBackward(tail);

    return 0;
}
