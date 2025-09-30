#include <stdio.h>
#include <stdlib.h> // For malloc()

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height; // Stores the height of the node, crucial for AVL balancing.
};

// Function to get height of a node
int height(struct Node* node) {
    if (node == NULL) return 0; // Height of a NULL node is 0.
    return node->height;
}

// Utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1; // A new node is a leaf, so its height is 1.
    return node;
}

// Function to perform a right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights after rotation (order matters: update children first)
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // 'x' is the new root of this subtree.
}

// Function to perform a left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // 'y' is the new root of this subtree.
}

// Get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    // Balance Factor = height(left subtree) - height(right subtree)
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int value) {
    // 1. Standard BST Insertion
    if (node == NULL) return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else // Duplicate values are not allowed
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor to check if this node became unbalanced
    int balance = getBalance(node);

    // 4. If unbalanced, there are 4 cases:
    // Left Left Case: balance > 1 and new value is in the left subtree of the left child
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case: balance < -1 and new value is in the right subtree of the right child
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case: balance > 1 and new value is in the right subtree of the left child
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left); // First, left rotate the left child
        return rightRotate(node);          // Then, right rotate the current node
    }

    // Right Left Case: balance < -1 and new value is in the left subtree of the right child
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right); // First, right rotate the right child
        return leftRotate(node);           // Then, left rotate the current node
    }

    // Return the (possibly new) root of the subtree
    return node;
}

// Inorder traversal to display the tree (will print sorted values)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int value = 13;

    // Insert multiples of 13
    for (int i = 0; i < 5; i++) {
        root = insert(root, value);
        printf("%d inserted\n", value);
        value += 13;
    }

    // Display AVL tree using inorder (will always be sorted)
    printf("\nInorder Traversal of AVL Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
