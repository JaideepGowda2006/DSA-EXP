#include <stdio.h>
#include <stdlib.h>

// Node structure for a tree, with left and right child pointers.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node.
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST (using recursion).
struct Node* insert(struct Node* root, int value) {
    // Base Case: If the current node is NULL, we've found the spot to insert.
    if (root == NULL) {
        return createNode(value);
    }
    // Recursive Step: Decide whether to go left or right.
    if (value < root->data) {
        // The new node belongs in the left subtree.
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // The new node belongs in the right subtree.
        root->right = insert(root->right, value);
    }
    // If value == root->data, we do nothing (no duplicates).
    return root; // Return the (possibly modified) root pointer.
}

// Inorder traversal (Left, Root, Right).
// For a BST, this will always print the elements in sorted order.
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);  // First, visit the left child.
        printf("%d ", root->data); // Then, visit the root itself.
        inorder(root->right); // Finally, visit the right child.
    }
}

// Helper function to find the node with the minimum value in a subtree.
// This is done by always traversing to the leftmost node.
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node.
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root; // Base case: value not found.

    // Find the node to delete.
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else { // This is the node to be deleted.
        // Case 1 & 2: Node with only one child or no child.
        if (root->left == NULL) {
            struct Node* temp = root->right;
            printf("Deleted: %d\n", root->data);
            free(root);
            return temp; // The right child becomes the new root of this subtree.
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            printf("Deleted: %d\n", root->data);
            free(root);
            return temp; // The left child becomes the new root.
        }

        // Case 3: Node with two children.
        // Find the inorder successor (smallest node in the right subtree).
        struct Node* temp = minValueNode(root->right);
        // Copy the inorder successor's data to this node.
        root->data = temp->data;
        // Now, delete the inorder successor from the right subtree.
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int value = 13;

    // Insert 5 nodes.
    for (int i = 0; i < 5; i++) {
        root = insert(root, value);
        printf("%d inserted\n", value);
        value += 13;
    }

    // Display the BST using inorder traversal.
    printf("\nInorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    // Delete two nodes.
    printf("\nDeleting two nodes...\n");
    root = deleteNode(root, 13);
    root = deleteNode(root, 26);

    // Display again to see the result.
    printf("\nInorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
