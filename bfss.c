#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int queue[MAX],front =-1,rear=-1;

void enqueue(int x)
{
    if(rear==MAX-1)
    {
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=x;
}
int dequeue()
{
    if(front==-1 || front>rear) return -1;
    return queue[front++];
}

int isEmpty()
{
    return (front==-1||front>rear);
}

void BFS(int adj[][MAX],int n,int s)
{
    int visited[MAX]={0};

    printf("BFS Travesal :");

    enqueue(s);
    visited[s]=1;

    while(!isEmpty())
    {
        int v = dequeue();
        printf("%d ",v);

        for(int i=0; i<n; i++)
        {
            if(adj[v][i]==1&&!visited[i])
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter Number of vertices :");
    scanf("%d",&n);

    int adj[MAX][MAX];

    printf("Enter the Adjacency Matrix :\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    int start;
    printf("Enter the starting vertex for BFS :");
    scanf("%d",&start);

    BFS(adj,n,start);

    return 0;
}