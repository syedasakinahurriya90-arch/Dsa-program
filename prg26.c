#include <stdio.h>
#include <stdlib.h>

// Function Declarations
struct node* insert(struct node *root, int value);
void inorder(struct node *root);
struct node* search(struct node *root, int key);

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
    int n, i, value, key;

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

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if(search(root, key) != NULL)
        printf("Element found");
    else
        printf("Element not found");

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

// Inorder Traversal
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search Function
struct node* search(struct node *root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}