#include <stdio.h>

#define MAX 100

int heap[MAX];
int n = 0;   // heap size

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Max-Heapify (fix down)
void heapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Build max heap
void buildMaxHeap() {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(i);
}

// Extract max
int extractMax() {
    if (n == 0) return -1;

    int max = heap[0];
    heap[0] = heap[n - 1];
    n--;

    heapify(0);
    return max;
}

// Heapsort (ascending)
void heapSort() {
    printf("\nSorted elements: ");
    while (n > 0) {
        int max = extractMax();
        printf("%d ", max);
    }
}

int main() {
    printf("Enter heap size: ");
    scanf("%d", &n);

    printf("Enter numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    buildMaxHeap();

    printf("\nMax Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    heapSort();

    return 0;
}