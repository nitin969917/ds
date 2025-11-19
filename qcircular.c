#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1,rear=-1;

int isFull()
{
    return (front == (rear+1)%SIZE);
}

int isEmpty()
{
    return (front==-1);
}

void enqueue(int x)
{
    if(isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if(front == -1)
        front=0;
    rear = (rear+1)%SIZE;
    queue[rear]=x;
    printf("%d inserted into queue\n",x);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    int val = queue[front];
    printf("%d removed from queue\n",val);

    if(front==rear)
    {
        front=rear=-1;
    }else{
        front = (front+1)%SIZE;
    }
}

void dispFirst()
{
    if(isEmpty())
        printf("Queue is Empty\n");
    else  
        printf("Front Element :%d\n",queue[front]);
}

void dispRear()
{
    if(isEmpty())
        printf("Queue is Empty\n");
    else
        printf("Rear Element:%d\n",queue[rear]);
}

void disp()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements :");
    int i=front;
    while(1)
    {
        printf("%d ",queue[i]);
        if(i==rear)
            break;
        i= (i+1)%SIZE;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    disp();
    
    dequeue();
    disp();
    enqueue(60);
    enqueue(80);

    disp();
    dispFirst();
    dispRear();

    return 0;
}