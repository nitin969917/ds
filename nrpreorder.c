#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* create(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// Create tree recursively
struct Node* createTree() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* root = create(x);
    printf("Enter left child of %d\n", x);
    root->left = createTree();

    printf("Enter right child of %d\n", x);
    root->right = createTree();

    return root;
}

// Non-recursive Preorder
void preorderNR(struct Node* root) {
    if (!root) return;

    struct Node* stack[50];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}

int main() {
    struct Node* root = createTree();

    printf("\nNon-Recursive Preorder Traversal: ");
    preorderNR(root);

    return 0;
}