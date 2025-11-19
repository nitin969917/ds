#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct node* root = NULL;
    int n,val;
    printf("Enter the number of Nodes :");
    scanf("%d",&n);

    printf("Enter the Values :");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&val);
        root = insert(root,val);
    }

    printf("\nInorder Traversal :");
    inorder(root);

    printf("\nPreorder Traversal :");
    preorder(root);

    printf("\nPostorder Traversal :");
    postorder(root);

    return 0;
}