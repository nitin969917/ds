#include<stdio.h>
int graph[10][10];
int visited[10];
int n;

void DFS(int v)
{
    printf("%d ",v);
    visited[v]=1;
    for(int i=0; i<n; i++)
    {
        if(graph[v][i]==1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    printf("Enter the number of vertices :");
    scanf("%d",&n);

    printf("Enter Adjacency Matrix :\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }

    int s;
    printf("Enter starting vertex :");
    scanf("%d",&s);
    printf("DFS Traversal :");
    DFS(s);
    return 0;
}