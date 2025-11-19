#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100
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

void reverse(char exp[])
{
    int len = strlen(exp);
    for(int i=0; i<len/2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[len-i-1];
        exp[len-i-1] = temp;
    }
}

int main()
{
    char exp[MAX],temp[MAX];
    char x;
    int j=0;

    printf("Enter the infix expression :");
    scanf("%s",exp);

    reverse(exp);

    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
    }

    printf("\nPreFix Expression :");
    for(int i=0; exp[i]!='\0'; i++)
    {
        char c = exp[i];

        if(isalnum(c))
            temp[j++]=c;
        else if(c=='(')
            push(c);
        else if(c==')')
        {
            while((x=pop())!='(')
            {
                temp[j++]=x;
            }
        }else{
            while(top!=-1 && precedence(stack[top])>=precedence(c))
            {
                temp[j++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        temp[j++]=pop();
    }
    temp[j]='\0';

    reverse(temp);
    
    printf("%s",temp);

    return 0;
}