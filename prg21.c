#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

/* Function Declarations */
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
void display();

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}

/* Insert at Front */
void insertFront(int x)
{
    if((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = x;
}

/* Insert at Rear */
void insertRear(int x)
{
    if((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = x;
}

/* Delete from Front */
void deleteFront()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted Element = %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
}

/* Delete from Rear */
void deleteRear()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted Element = %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

/* Display Deque */
void display()
{
    int i;

    if(front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque Elements: ");

    i = front;
    while(i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", deque[rear]);
}