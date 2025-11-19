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
    newNode->next=NULL;
    return newNode;
}

struct node* insert(struct node* poly,int coeff,int exp)
{
    struct node* newNode = createNode(coeff,exp);

    if(poly==NULL)
    {
        return newNode;
    }
    struct node* temp = poly;
    while(temp->next!=NULL)
    {
        temp = temp->next;
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
        poly= poly->next;
        if(poly!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct node* add(struct node* poly1,struct node* poly2)
{
    struct node* res = NULL;

    while(poly1!=NULL && poly2!=NULL)
    {
        if(poly1->exp >poly2->exp)
        {
            res = insert(res,poly1->coeff,poly1->exp);
            poly1 = poly1->next;
        }else if(poly1->exp < poly2->exp)
        {
            res = insert(res,poly2->coeff,poly2->exp);
            poly2= poly2->next;
        }else{
            res = insert(res,poly1->coeff+poly2->coeff,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }

    while(poly1!=NULL)
    {
        res = insert(res,poly1->coeff,poly1->exp);
        poly1 = poly1->next;
    }

    while(poly2!=NULL)
    {
        res = insert(res,poly2->coeff,poly2->exp);
        poly2= poly2->next;
    }
    return res;
}

int main()
{
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* sum = NULL;

    poly1 = insert(poly1,3,3);
    poly1 = insert(poly1,2,2);
    poly1 = insert(poly1,1,0);

    poly2 = insert(poly2,4,2);
    poly2 = insert(poly2,5,1);
    poly2 = insert(poly2,2,0);

    printf("Polynomial 1:");
    display(poly1);

    printf("Polynomial 2:");
    display(poly2);

    sum = add(poly1,poly2);

    printf("Addition :");
    display(sum);

    return 0;
}