#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// index of preorder
int preIndex = 0;

struct Node* buildTree(int inorder[], int preorder[], int start, int end) {
    if (start > end)
        return NULL;

    // take current preorder element as root
    struct Node* root = create(preorder[preIndex++]);

    // if leaf node
    if (start == end)
        return root;

    // find root in inorder
    int pos = search(inorder, start, end, root->data);

    // build left and right subtrees
    root->left = buildTree(inorder, preorder, start, pos - 1);
    root->right = buildTree(inorder, preorder, pos + 1, end);

    return root;
}

// recursive postorder
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int inorder[]  = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int n = 5;

    struct Node* root = buildTree(inorder, preorder, 0, n - 1);

    printf("Postorder Traversal: ");
    postorder(root);

    return 0;
}