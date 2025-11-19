#include<stdio.h>
#include<stdlib.h>

struct node
{
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

void insertEnd(struct node** head ,int data)
{
    struct node* newNode = createNode(data);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int isPalindrome(struct node* head)
{
    int arr[100],i=0;
    struct node* temp = head;

    while(temp!=NULL)
    {
        arr[i++]=temp->data;
        temp=temp->next;
    }

    int s=0;
    int e=i-1;

    while(s<i)
    {
        if(arr[s]!=arr[e])
            return 0;
        s++;
        e--;
    }
    return 1;
}

void disp(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{   
    struct node* head = NULL;

    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,1);
    insertEnd(&head,3);
    
    printf("\nLinked List :");
    disp(head);

    if(isPalindrome(head))
    {
        printf("List is Palindrome");
    }else{
        printf("List is not Palindrome");
    }
    return 0;
}