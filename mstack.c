#include<stdio.h>
#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x)
{
    if(top1+1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top1]=x;
}

void push2(int x)
{
    if(top2-1==top1)
    {
        printf("Stack Overflow\n");
    }
    stack[--top2]=x;
}

int pop1()
{
    if(top1==-1)
    {
        printf("Stack 1 UnderFlow\n");
        return -1;
    }
    return stack[top1--];
}

int pop2()
{
    if(top2==MAX)
    {
        printf("Stack 2 UnderFlow\n");
        return -1;
    }
    return stack[top2++];
}

void display()
{
    int i;
    printf("\nStack 1 :");
    for(int i=0; i<=top1; i++)
    {
        printf("%d ",stack[i]);
    }

    printf("\nStack 2 :");
    for(int i=MAX-1; i>=top2; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int ch,val;

    while(1)
    {
        printf("\n---Menu----\n");
        printf("1.Push in stack 1\n");
        printf("2.Push in stack 2\n");
        printf("3.Pop from stack 1\n");
        printf("4.Pop from stack 2\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value :");
                scanf("%d",&val);
                push1(val);
                break;
            case 2:
                printf("Enter value :");
                scanf("%d",&val);
                push2(val);
                break;
            
            case 3:
                printf("Popped from stack 1:%d\n",pop1());
                break;
            
            case 4:
                printf("Popped from stack 1:%d\n",pop2());
                break;
            
            case 5:
                display();
                break;
            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }


    return 0;
}