#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert()
{
    struct node *newnode, *temp;
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &x);

    newnode->data = x;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted.\n");
}

// Delete from beginning
void deleteNode()
{
    struct node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }

    printf("Node deleted.\n");
}

// Display
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            deleteNode();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}