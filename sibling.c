#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// Check if two trees are equal
int isEqual(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    return (a->data == b->data &&
            isEqual(a->left, b->left) &&
            isEqual(a->right, b->right));
}

// Create mirror image
void mirror(struct Node* root) {
    if (root == NULL) return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder print (to show output)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // ---------- Hardcoded Tree 1 ----------
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    // ---------- Hardcoded Tree 2 ----------
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    // 1. Check if equal
    if (isEqual(root1, root2))
        printf("Trees are Equal\n");
    else
        printf("Trees are NOT Equal\n");

    // 2. Make mirror of Tree 1
    printf("\nTree 1 before mirror (Inorder): ");
    inorder(root1);

    mirror(root1);

    printf("\nTree 1 after mirror (Inorder): ");
    inorder(root1);

    printf("\n");
    return 0;
}