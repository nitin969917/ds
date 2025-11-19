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

// Rotate list by k places
struct Node* rotate(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    // Find length
    int len = 1;
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    // Connect last node to head (make circular)
    temp->next = head;

    // Normalize k
    k = k % len;

    // Move (len - k) steps
    int steps = len - k;
    while (steps--) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break circle
    temp->next = NULL;

    return head;
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
    // Linked list: 1 → 2 → 3 → 4 → 5
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 1;

    head = rotate(head, k);

    printf("Rotated List: ");
    printList(head);

    return 0;
}
