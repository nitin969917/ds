#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// create node
struct Node* create(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// count total nodes
int totalNodes(struct Node *root) {
    if (root == NULL) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

// count terminal (leaf) nodes
int leafNodes(struct Node *root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leafNodes(root->left) + leafNodes(root->right);
}

// count non-terminal (internal) nodes
int internalNodes(struct Node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return 1 + internalNodes(root->left) + internalNodes(root->right);
}

int main() {
    // Hardcoded Binary Tree
    struct Node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Total Nodes: %d\n", totalNodes(root));
    printf("Leaf Nodes: %d\n", leafNodes(root));
    printf("Internal Nodes: %d\n", internalNodes(root));

    return 0;
}