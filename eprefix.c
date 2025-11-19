#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
int stack[MAX];
int top =-1;

void push(int x)
{
    stack[++top]=x;
}

char pop()
{
    return stack[top--];
}

int evaluate(char exp[])
{
    int i;
    int len = strlen(exp);

    for(int i=len-1; i>=0; i--)
    {
        char ch = exp[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            int val1 = pop();
            int val2 = pop();

            int res;

            switch(ch)
            {
                case '+':
                    res = val1+val2;
                    break;
                case '-':
                    res = val1-val2;
                    break;
                case '*':
                    res = val1*val2;
                    break;
                case '/':
                    res = val1/val2;
                    break;
            }
            push(res);
        }
    }
    return pop();
}

int main()
{
    char exp[100];
    printf("Enter prefix Expression :");
    scanf("%s",exp);

    int res = evaluate(exp);
    printf("Result :%d\n",res);

    return 0;
}