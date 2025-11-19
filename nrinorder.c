#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// create new node
struct Node* create(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// non-recursive inorder using stack
void inorder(struct Node *root) {
    struct Node *stack[50];
    int top = -1;
    struct Node *curr = root;

    while (curr != NULL || top != -1) {

        // go to left most node
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        // pop and print
        curr = stack[top--];
        printf("%d ", curr->data);

        // move to right subtree
        curr = curr->right;
    }
}

int main() {

    // Hardcoded binary tree
    struct Node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Non-Recursive Inorder Traversal: ");
    inorder(root);

    return 0;
}