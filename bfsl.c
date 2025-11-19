#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct node* adj[20];
int queue[20],front=0,rear=0;
int visited[20];

void addEdge(int u,int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex=v;
    newNode->next=adj[u];
    adj[u]=newNode;
}

void enqueue(int v)
{
    queue[rear++]=v;
}
int dequeue()
{
    return queue[front++];
}

void bfs(int start)
{
    printf("BFS Traversal :");

    visited[start]=1;
    enqueue(start);

    while(front<rear)
    {
        int v = dequeue();
        printf("%d ",v);

        struct node* temp = adj[v];
        while(temp!=NULL)
        {
            if(!visited[temp->vertex])
            {
                visited[temp->vertex]=1;
                enqueue(temp->vertex);
            }
            temp=temp->next;
        }
    }
}

void display(int n)
{
    printf("\nAdjacency List :\n");
    for(int i=0; i<n;i++)
    {
        printf("%d -> ",i);
        struct node* temp = adj[i];
        while(temp)
        {
            printf("%d -> ",temp->vertex);
            temp= temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n,e,u,v,start;

    printf("Enter number of vertices :");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        adj[i]=NULL;
    }

    printf("Enter the number of edges :");
    scanf("%d",&e);

    printf("Enter edges (u v) :\n");
    for(int i=0; i<e; i++)
    {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }

    display(n);

    printf("\nEnter starting vertex for BFS :");
    scanf("%d",&start);

    bfs(start);

    return 0;
}