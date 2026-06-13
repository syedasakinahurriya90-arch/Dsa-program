#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int item;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Circular Queue is Full\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    cq[rear] = item;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Deleted element = %d\n", cq[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Elements are: ");

    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    else
    {
        for (i = front; i < MAX; i++)
            printf("%d ", cq[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", cq[i]);
    }

    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}