#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insert(struct node* head ,int data)
{
    struct node* newNode = createNode(data);

    if(head==NULL)
    {
        head = newNode;
        return head;
    }

    struct node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    return head;
}

void display(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct node* removoDuplicates(struct node* head)
{
    if(head == NULL)
        return head;
    
    struct node* curr = head;

    while(curr->next!=NULL)
    {
        if(curr->data == curr->next->data)
        {
            struct node* duplicate = curr->next;
            curr->next = duplicate->next;
            free(duplicate);
        }else{
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    struct node* head =NULL;

    head = insert(head,1);
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,3);
    head = insert(head,4);

    printf("Original List :");
    display(head);

    head = removoDuplicates(head);

    printf("After Removing Duplcates:");
    display(head);

    return 0;
}