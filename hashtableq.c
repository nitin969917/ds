#include<stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initilize()
{
    for(int i=0; i<SIZE; i++)
    {
        hashTable[i]=-1;
    }
}

int hash(int key)
{
    return key%SIZE;
}

void insert(int key)
{
    int index = hash(key);

    if(hashTable[index]==-1)
    {
        hashTable[index]=key;
        printf("inserted %d at index %d\n",key,index);
        return;
    }

    int i=1;

    while(i<SIZE)
    {
        int newIndex = (index+i*i)%SIZE;

        if(hashTable[newIndex]==-1)
        {
            hashTable[newIndex]=key;
            printf("inserted %d at index %d\n",key,newIndex);
            return;
        }
        i++;
    }

    printf("Hash Table is Full cannot insert %d\n",key);
}

int search(int key)
{
    int index = hash(key);

    if(hashTable[index]==key)
    {
        return index;
    }

    int i=1;
    while(i<SIZE)
    {
        int newIndex = (index+i*i)%SIZE;

        if(hashTable[newIndex]==key)
        {
            return newIndex;
        }
        if(hashTable[newIndex]==-1)
        {
            return -1;
        }
        i++;
    }
    return -1;
}

int main() {
    initilize();

    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2: {
                printf("Enter key to search: ");
                scanf("%d", &key);
                int pos = search(key);
                if (pos == -1)
                    printf("Key not found!\n");
                else
                    printf("Key found at index %d\n", pos);
                break;
            }

            case 3:
                printf("\nHash Table:\n");
                for (int i = 0; i < SIZE; i++)
                    printf("Index %d → %d\n", i, hashTable[i]);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}