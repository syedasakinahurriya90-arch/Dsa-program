#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int s[MAX];
int front = -1, rear = -1;

void qins(){
    int data;

    if (rear >= MAX - 1){
        printf("Queue Overflow\n");
    }
    else{
        if (front == -1){
            front = 0;
        }
        printf("Enter element: ");
        scanf("%d", &data);

        rear++;
        s[rear] = data;
    }
}
void dequeue(){
    if (front == -1 || front > rear){
        printf("Queue Underflow\n");
    }
    else{
        printf("Deleted element: %d\n", s[front]);
       front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Queue Using Array ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                qins();
                break;

            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}