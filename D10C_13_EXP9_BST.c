#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find minimum value node
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            printf("Deleted: %d\n", root->data);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            printf("Deleted: %d\n", root->data);
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int value = 13; // multiples of 13

    // Insert 5 nodes
    for (int i = 0; i < 5; i++) {
        root = insert(root, value);
        printf("%d inserted\n", value);
        value += 13;
    }

    // Display BST using inorder (sorted)
    printf("\nInorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    // Delete two nodes
    printf("\nDeleting two nodes...\n");
    root = deleteNode(root, 13);
    root = deleteNode(root, 26);

    // Display again
    printf("\nInorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

