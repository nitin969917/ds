#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Insert at end
struct Node* insert(struct Node* head, int x) {
    struct Node* n = createNode(x);

    if (head == NULL)
        return n;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;

    return head;
}

// Delete first occurrence of x
struct Node* delete(struct Node* head, int x) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found!\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, x, n;

    while (1) {
        printf("\n1.Create  2.Display  3.Insert  4.Delete  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &x);
                head = insert(head, x);
            }
        }

        else if (choice == 2)
            display(head);

        else if (choice == 3) {
            printf("Enter element to insert: ");
            scanf("%d", &x);
            head = insert(head, x);
        }

        else if (choice == 4) {
            printf("Enter element to delete: ");
            scanf("%d", &x);
            head = delete(head, x);
        }

        else if (choice == 5)
            break;

        else
            printf("Invalid choice!\n");
    }
    return 0;
}