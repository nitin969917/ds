#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// Create a new node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int x) {
    struct Node* n = newNode(x);

    if (head == NULL)
        return n;

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;

    return head;
}

// Concatenate list2 at end of list1
struct Node* concatenate(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* temp = l1;
    while (temp->next)
        temp = temp->next;

    temp->next = l2;
    l2->prev = temp;

    return l1;
}

// Display
void display(struct Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node *l1 = NULL, *l2 = NULL;
    int n, x;

    // List 1
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    // List 2
    printf("\nEnter number of elements in List 2: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    printf("\nList 1: ");
    display(l1);

    printf("List 2: ");
    display(l2);

    // Concatenate
    l1 = concatenate(l1, l2);

    printf("\nAfter concatenation: ");
    display(l1);

    return 0;
}