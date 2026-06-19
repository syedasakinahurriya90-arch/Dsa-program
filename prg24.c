#include <stdio.h>
#include <stdlib.h>

// Function Declarations
struct node* insert(struct node *root, int value);
void postorder(struct node *root);

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

    printf("Postorder Traversal: ");
    postorder(root);

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
    else if(value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate element not allowed\n");

    return root;
}

// Postorder Traversal Function
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}