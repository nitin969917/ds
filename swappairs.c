#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Swap nodes in pairs
struct Node* swapPairs(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = head->next;  // 2nd node becomes new head
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct Node* nxt = curr->next;

        // Swapping
        curr->next = nxt->next;
        nxt->next = curr;

        if (prev != NULL)
            prev->next = nxt;

        prev = curr;
        curr = curr->next;
    }

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // List : 1 → 2 → 3 → 4
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    head = swapPairs(head);

    printf("Swapped List: ");
    printList(head);

    return 0;
}