#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// Create Binary Tree (recursive)
struct Node* create() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* root = newNode(x);

    printf("Enter left child of %d:\n", x);
    root->left = create();

    printf("Enter right child of %d:\n", x);
    root->right = create();

    return root;
}

// Inorder Traversal (LNR)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Height of Tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

int main() {
    struct Node* root = NULL;

    printf("Create the tree:\n");
    root = create();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\n\nHeight of Tree: %d\n", height(root));

    return 0;
}