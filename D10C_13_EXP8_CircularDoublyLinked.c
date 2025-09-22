#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the end
struct Node* insertEnd(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (tail == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;  // head
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
    printf("%d inserted\n", value);
    return tail;
}

// Display forward
void displayForward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail->next; // head
    printf("CDLL Forward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Display backward
void displayBackward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail;
    printf("CDLL Backward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("%d\n", tail->data); // print last element again to complete circle
}

// Delete first node
struct Node* deleteFirst(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* head = tail->next;
    if (head == tail) { // only one node
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }
    tail->next = head->next;
    head->next->prev = tail;
    printf("Deleted: %d\n", head->data);
    free(head);
    return tail;
}

int main() {
    struct Node* tail = NULL;
    int value = 13; // multiples of 13

    // Insert 5 nodes
    for (int i = 0; i < 5; i++) {
        tail = insertEnd(tail, value);
        value += 13;
    }

    // Display list forward and backward
    displayForward(tail);
    displayBackward(tail);

    // Delete first two nodes
    printf("\nDeleting two nodes...\n");
    tail = deleteFirst(tail);
    tail = deleteFirst(tail);

    // Display again
    displayForward(tail);
    displayBackward(tail);

    return 0;
}

