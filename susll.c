#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push (insert at beginning)
void push(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

// Pop (remove from beginning)
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Display topmost element
void displayTop() {
    if (top == NULL)
        printf("Stack is empty!\n");
    else
        printf("Top Element: %d\n", top->data);
}

// Display entire stack
void displayStack() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Push  2.Pop  3.Display Top  4.Display Stack  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &x);
            push(x);
        }
        else if (choice == 2)
            pop();
        else if (choice == 3)
            displayTop();
        else if (choice == 4)
            displayStack();
        else if (choice == 5)
            break;
        else
            printf("Invalid choice!\n");
    }
    return 0;
}