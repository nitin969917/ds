#include<stdio.h>
#define MAX 100

int heap[MAX];
int n=0;

void swap(int *a,int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}

void heapify(int i)
{
    int smallest =i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && heap[left]<heap[smallest])
    {
        smallest=left;
    }
    if(right<n && heap[right]<heap[smallest])
    {
        smallest=right;
    }

    if(smallest!=i)
    {
        swap(&heap[i],&heap[smallest]);
        heapify(smallest);
    }
}

void buildMinHeap()
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(i);
    }
}

int extractMin()
{
    if(n==0)
    {
        return -1;
    }

    int min =heap[0];
    heap[0]=heap[n-1];
    n--;

    heapify(0);
    return min;
}

void heapSort()
{
    printf("\nSorted Elements :");
    while (n>0)
    {
        int min = extractMin();
        printf("%d ",min);
    }
}

int main()
{
    printf("Enter the heap Size :");
    scanf("%d",&n);

    printf("Enter Numbers :");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&heap[i]);
    }

    buildMinHeap();

    printf("\nMean Heap :");
    for(int i=0; i<n; i++)
    {
        printf("%d ",heap[i]);
    }

    heapSort();
    return 0;
}