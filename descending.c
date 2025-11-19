#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// Insert into BST
struct Node* insert(struct Node* root, int x) {
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Print in DESCENDING order → Right, Root, Left
void printDescending(struct Node* root) {
    if (root == NULL)
        return;

    printDescending(root->right);
    printf("%d ", root->data);
    printDescending(root->left);
}

int main() {
    struct Node* root = NULL;
    int n, x;

    printf("How many elements to insert? ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("\nBST in Descending Order: ");
    printDescending(root);

    printf("\n");
    return 0;
}