#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the end
struct Node* insertEnd(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (tail == NULL) {
        newNode->next = newNode; // points to itself
        tail = newNode;
    } else {
        newNode->next = tail->next; // points to head
        tail->next = newNode;
        tail = newNode;
    }
    printf("%d inserted\n", value);
    return tail;
}

// Function to display circular linked list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail->next; // start from head
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Function to delete first node
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
    printf("Deleted: %d\n", head->data);
    free(head);
    return tail;
}

int main() {
    struct Node* tail = NULL;
    int value = 13; // start with multiples of 13

    // Insert 5 nodes
    for (int i = 0; i < 5; i++) {
        tail = insertEnd(tail, value);
        value += 13;
    }

    // Display list
    display(tail);

    // Delete first two nodes
    printf("\nDeleting two nodes...\n");
    tail = deleteFirst(tail);
    tail = deleteFirst(tail);

    // Display list again
    display(tail);

    return 0;
}

