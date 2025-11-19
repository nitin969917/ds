#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
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

    printf("Enter left child of %d:\n", x);
    root->left = createTree();

    printf("Enter right child of %d:\n", x);
    root->right = createTree();

    return root;
}

// Non-Recursive Postorder (Using two stacks)
void postorderNR(struct Node* root) {
    if (root == NULL) return;

    struct Node* s1[50], *s2[50];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1) {
        struct Node* curr = s1[top1--];
        s2[++top2] = curr;

        if (curr->left)
            s1[++top1] = curr->left;
        if (curr->right)
            s1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", s2[top2--]->data);
    }
}

int main() {
    struct Node* root = createTree();

    printf("\nNon-Recursive Postorder Traversal: ");
    postorderNR(root);

    return 0;
}