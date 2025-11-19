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
    
    while(hashTable[index]!=-1)
    {
        index=(index+1)%SIZE;
    }

    hashTable[index] = key;
    printf("Insertion %d at index %d\n",key,index);
}

int search(int key)
{
    int index = hash(key);
    int start = index;

    while(hashTable[index]!=-1)
    {
        if(hashTable[index]==key)
        {
            return index;
        }
        index = (index+1)%SIZE;

        if(index==start)
        {
            return -1;
        }
        
    }
    return -1;
}

int main()
{
    initilize();
    int choice,key;

    while(1)
    {
        printf("\n1.Insert \n2.Search\n3.Display\n4.Exit");
        printf("\nEnter your choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter key to Insert :");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                printf("Enter the Key to Search :");
                scanf("%d",&key);
                int pos = search(key);
                if(pos==-1)
                {
                    printf("key not found\n");
                }else{
                    printf("key found at index %d\n",pos);
                }
                break;
            case 3:
                printf("\nHash Table\n");
                for(int i=0; i<SIZE; i++)
                {
                    printf("Index %d -> %d\n",i,hashTable[i]);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }


    }

    return 0;
}