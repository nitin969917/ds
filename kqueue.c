#include<stdio.h>
#include<stdlib.h>

#define MAX 20
#define K 3

int arr[MAX];
int front[K],rear[K];
int size;

void initilize()
{
    size = MAX/K;
    for(int i=0; i<K; i++)
    {
        front[i]=-1;
        rear[i]=-1;
    }
}

void enqueue(int x,int qn)
{
    int s = qn*size;
    int e = s+size-1;

    if(rear[qn]==e)
    {
        printf("Queue %d is Full\n",qn);
        return;
    }

    if(front[qn]==-1)
    {
        front[qn]=s;
        rear[qn]=s;
    }else{
        rear[qn]++;
    }
    arr[rear[qn]]=x;
    printf("Enqueued %d into Queue %d\n",x,qn);
}

void dequeue(int qn)
{
    if(front[qn]==-1 || front[qn]>rear[qn])
    {
        printf("Queue %d is Empty\n",qn);
        return;
    }

    int val = arr[front[qn]];
    front[qn]++;
    printf("\nDequeued %d from Queue %d",val,qn);
}

void display(int qn)
{
    if(front[qn]==-1||front[qn]>rear[qn])
    {
        printf("Queue %d is empty\n",qn);
        return;
    }

    printf("Queue %d elements :",qn);
    for(int i= front[qn]; i<=rear[qn]; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void displayAll()
{
    for(int i=0; i<K; i++)
    {
        display(i);
    }
}

int main()
{
    initilize();

    enqueue(10,0);
    enqueue(20,0);
    enqueue(30,1);
    enqueue(40,1);
    enqueue(50,2);

    printf("\n---Displaying All Queues ----\n");
    displayAll();

    printf("\n---After Dequeue Operation----\n");
    dequeue(0);
    dequeue(1);

    displayAll();

    return 0;
}