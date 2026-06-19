#include <stdio.h>
#include <stdlib.h>

// Function Declarations
struct node* insert(struct node *root, int value);
void inorder(struct node *root);

// Structure Definition
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Main Function
int main()
{
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}

// Insert Function
struct node* insert(struct node *root, int value)
{
    if(root == NULL)
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));

        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder Traversal Function
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}