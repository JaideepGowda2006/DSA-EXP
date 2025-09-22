#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert node at the end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete first node
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

int main() {
    struct Node* head = NULL;
    int value = 13; // start with multiple of 13

    // Insert 5 nodes (multiples of 13)
    for (int i = 0; i < 5; i++) {
        head = insertEnd(head, value);
        printf("%d inserted\n", value);
        value += 13;
    }

    // Display list
    display(head);

    // Delete first 2 nodes
    printf("\nDeleting two nodes...\n");
    head = deleteFirst(head);
    head = deleteFirst(head);

    // Display list again
    display(head);

    return 0;
}

