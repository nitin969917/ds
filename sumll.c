#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int x) {
    struct Node* n = newNode(x);

    if (head == NULL)
        return n;

    struct Node* t = head;
    while (t->next)
        t = t->next;

    t->next = n;
    return head;
}

// Reverse list (helps in addition)
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Add two lists
struct Node* addLists(struct Node* a, struct Node* b) {
    a = reverse(a);
    b = reverse(b);

    struct Node* res = NULL;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;

        if (a) { sum += a->data; a = a->next; }
        if (b) { sum += b->data; b = b->next; }

        carry = sum / 10;
        sum = sum % 10;

        res = insertEnd(res, sum);
    }

    return reverse(res);
}

// Display list
void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *l1 = NULL, *l2 = NULL;
    int n, x;

    printf("Enter number of digits in List 1: ");
    scanf("%d", &n);
    printf("Enter digits (MSD first):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    printf("Enter number of digits in List 2: ");
    scanf("%d", &n);
    printf("Enter digits (MSD first):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    printf("\nNumber 1: "); display(l1);
    printf("Number 2: "); display(l2);

    struct Node* sum = addLists(l1, l2);

    printf("\nSum: ");
    display(sum);

    return 0;
}