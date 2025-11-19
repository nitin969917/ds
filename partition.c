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

struct node* insert(struct node* head,int data)
{
    struct node* newNode = createNode(data);

    if(head==NULL)
    {
        return newNode;
    }

    struct node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void display(struct node* head)
{
    while(head != NULL)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node* partition(struct node* head,int x)
{
    struct node *lessH=NULL,*lessT=NULL;
    struct node *moreH=NULL,*moreT=NULL;

    struct node* curr = head;

    while(curr != NULL)
    {
        struct node* nextNode = curr->next; // IMPORTANT
        curr->next = NULL;                  // BREAK LINK

        if(curr->data < x)
        {
            if(lessH == NULL)
                lessH = lessT = curr;
            else
            {
                lessT->next = curr;
                lessT = curr;
            }
        }
        else
        {
            if(moreH == NULL)
                moreH = moreT = curr;
            else
            {
                moreT->next = curr;
                moreT = curr;
            }
        }

        curr = nextNode;   // MOVE SAFE
    }

    if(lessH == NULL) return moreH;

    lessT->next = moreH;
    return lessH;
}

int main()
{
    struct node* head = NULL;

    head=insert(head,1);
    head=insert(head,5);
    head=insert(head,3);
    head=insert(head,2);
    head=insert(head,4);
    head=insert(head,2);

    printf("\nOriginal List :");
    display(head);

    int x=3;
    head=partition(head,x);

    printf("Partitioned List(x=%d):",x);
    display(head);

    return 0;
}