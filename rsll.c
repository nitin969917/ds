#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create() {
    int x;
    printf("Enter value (-1 to stop): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = create();
    return newNode;
}

void display(struct Node* head) {
    if (head == NULL)
        return;
    printf("%d ", head->data);
    display(head->next);
}

int length(struct Node* head) {
    if (head == NULL)
        return 0;
    return 1 + length(head->next);
}

struct Node* reverse(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    struct Node* head = NULL;

    printf("Create Linked List:\n");
    head = create();

    printf("\nLinked List: ");
    display(head);

    printf("\nLength = %d\n", length(head));

    head = reverse(head);
    printf("Reversed List: ");
    display(head);

    return 0;
}