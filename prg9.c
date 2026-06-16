#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *temp, *newnode;

void insert()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted\n");
}

void delete()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    if(temp == head)
        head = NULL;
    else
        temp->prev->next = NULL;

    free(temp);

    printf("Node deleted\n");
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("List: ");

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}