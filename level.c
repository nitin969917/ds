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

// Create tree (recursive)
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

// Level Order Traversal using queue
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

int main() {
    struct Node* root = NULL;

    printf("Create the Binary Tree:\n");
    root = create();

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    printf("\n");
    return 0;
}