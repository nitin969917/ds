#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[20];
int visited[20];
int n;

void addEdge(int u,int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex=v;
    newNode->next=adj[u];
    adj[u]=newNode;
}

void DFS(int v)
{
    visited[v]=1;
    printf("%d ",v);
    struct node* temp = adj[v];
    while(temp!=NULL)
    {
        int nextVertex = temp->vertex;
        if(!visited[nextVertex])
        {
            DFS(nextVertex);
        }
        temp= temp->next;
    }
}

int main()
{
    printf("Enter number of verteces :");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        adj[i]=NULL;
    }

    int edges;
    printf("Enter number of edges :");
    scanf("%d",&edges);

    printf("Enter Edges (u v):\n");
    for(int i=0; i<edges; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }

    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }

    int start;
    printf("Enter starting vertex :");
    scanf("%d",&start);
    printf("DFS Traversal :");
    DFS(start);
    return 0;
}