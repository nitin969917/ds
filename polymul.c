#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node* next;
};

struct node* createNode(int coeff,int exp)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    return newNode;
}

struct node* insert(struct node* poly,int coeff,int exp)
{
    struct node* newNode=createNode(coeff,exp);

    if(poly==NULL)
    {
        return newNode;
    }

    struct node* temp = poly;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    return poly;
}

void display(struct node* poly)
{
    if(poly==NULL)
    {
        printf("0\n");
        return;
    }
    while(poly!=NULL)
    {
        printf("%dx^%d",poly->coeff,poly->exp);
        poly=poly->next;
        if(poly!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct node* addTerm(struct node* res ,int coeff,int exp)
{
    struct node* temp = res;
    struct node* pre =NULL;

    while(temp!=NULL)
    {
        if(temp->exp==exp)
        {
            temp->coeff = temp->coeff+coeff;
            return res;
        }
        pre =temp;
        temp = temp->next;
    }

    struct node* newNode = createNode(coeff,exp);
    if(res==NULL)
    {
        res = newNode;
    }else{
        pre->next = newNode;
    }

    return res;
}


struct node* multiply(struct node* poly1 , struct node* poly2)
{
    struct node* res = NULL;

    for(struct node* p1 = poly1; p1!=NULL; p1 = p1->next)
    {
        for(struct node* p2 = poly2; p2!=NULL; p2 = p2->next)
        {
            int coeff = p1->coeff*p2->coeff;
            int exp = p1->exp+p2->exp;
            res = addTerm(res,coeff,exp);
        }
    }
    return res;
}

int main()
{
    struct node* poly1=NULL;
    struct node* poly2=NULL;
    struct node* product =NULL;

    poly1 = insert(poly1,3,2);
    poly1 = insert(poly1,2,1);
    poly1 = insert(poly1,1,0);

    poly2 = insert(poly2,2,1);
    poly2 = insert(poly2,4,0);

    printf("Polynomial 1:");
    display(poly1);

    printf("Polynomial 2:");
    display(poly2);

    product = multiply(poly1,poly2);

    printf("Result :");
    display(product);

    return 0;
}