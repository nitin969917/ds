#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// Create new node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

// Insert after a given position
struct Node* insertAfterPos(struct Node* head, int pos, int x) {
    struct Node* n = newNode(x);
    if (head == NULL)      // empty list
        return n;

    struct Node* temp = head;
    int i = 1;

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position not found!\n");
        return head;
    }

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;

    return head;
}

// Sort the doubly linked list (simple bubble sort)
void sortList(struct Node* head) {
    if (!head) return;

    struct Node *i, *j;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Display list
void display(struct Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// MAIN
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, x, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* temp = newNode(x);
        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    printf("\nOriginal List: ");
    display(head);

    printf("\nEnter position after which to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &x);

    head = insertAfterPos(head, pos, x);

    printf("\nList after insertion: ");
    display(head);

    sortList(head);

    printf("\nList after sorting: ");
    display(head);

    return 0;
}