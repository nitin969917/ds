#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue (insert at end)
void enqueue(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if (rear == NULL) {     // empty queue
        front = rear = n;
        return;
    }

    rear->next = n;
    rear = n;
}

// Dequeue (remove from front)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);

    front = front->next;
    if (front == NULL)   // queue becomes empty
        rear = NULL;

    free(temp);
}

// Display Queue
void display() {
    struct Node* temp = front;

    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Front element
void displayFront() {
    if (front == NULL)
        printf("Queue is empty!\n");
    else
        printf("Front: %d\n", front->data);
}

// Rear element
void displayRear() {
    if (rear == NULL)
        printf("Queue is empty!\n");
    else
        printf("Rear: %d\n", rear->data);
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Front  5.Rear  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
        else if (choice == 4)
            displayFront();
        else if (choice == 5)
            displayRear();
        else if (choice == 6)
            break;
        else
            printf("Invalid choice!\n");
    }
    return 0;
}