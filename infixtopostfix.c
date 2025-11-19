#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 10
char stack[MAX];
int top =-1;


void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}

int precedence(char c)
{
    if(c=='(')
        return 0;
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    if(c=='^')
        return 3;
    return 0;
}

int main()
{
    char exp[MAX];
    char x;

    printf("Enter the infix expression :");
    scanf("%s",exp);

    printf("\nPostFix Expression :");
    for(int i=0; exp[i]!='\0'; i++)
    {
        char c = exp[i];

        if(isalpha(c))
            printf("%c",c);
        else if(c=='(')
            push(c);
        else if(c==')')
        {
            while((x=pop())!='(')
            {
                printf("%c",c);
            }
        }else{
            while(top!=-1 && precedence(stack[top])>=precedence(c))
            {
                printf("%c",c);
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }


    return 0;
}