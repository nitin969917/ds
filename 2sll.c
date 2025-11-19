#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

struct Node* insertAsc(struct Node* head, int x) {
    struct Node* n = createNode(x);

    if (head == NULL || x < head->data) {
        n->next = head;
        return n;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < x) {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;

    return head;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node *head = NULL, *tail = NULL;

    while (a != NULL && b != NULL) {
        struct Node* pick;

        if (a->data < b->data) {
            pick = a;
            a = a->next;
        } else {
            pick = b;
            b = b->next;
        }

        if (head == NULL) {
            head = tail = pick;
        } else {
            tail->next = pick;
            tail = pick;
        }
    }

    if (a != NULL) tail->next = a;
    else tail->next = b;

    return head;
}

int isEqual(struct Node* a, struct Node* b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

struct Node* copy(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* newHead = createNode(head->data);
    struct Node* temp = newHead;
    head = head->next;

    while (head != NULL) {
        temp->next = createNode(head->data);
        temp = temp->next;
        head = head->next;
    }

    return newHead;
}

int main() {
    struct Node *l1 = NULL, *l2 = NULL;
    int n, x;

    printf("Enter elements in List 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insertAsc(l1, x);
    }

    printf("Enter elements in List 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l2 = insertAsc(l2, x);
    }

    printf("List 1: ");
    display(l1);
    printf("List 2: ");
    display(l2);

    struct Node* merged = merge(l1, l2);
    printf("Merged List: ");
    display(merged);

    printf("Lists are %s\n", isEqual(l1, l2) ? "Equal" : "Not Equal");

    struct Node* c2 = copy(l1);
    printf("Copy of List 1: ");
    display(c2);

    return 0;
}
