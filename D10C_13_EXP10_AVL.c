#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get height
int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create new node
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1; // new node is initially at leaf
    return node;
}

// Right rotate
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Insert node
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else // duplicate values not allowed
        return node;

    // update height
    node->height = 1 + max(height(node->left), height(node->right));

    // get balance
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
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

    // Display AVL tree using inorder (sorted)
    printf("\nInorder Traversal of AVL Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

