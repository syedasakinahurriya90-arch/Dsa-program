#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node*top=NULL;
void push();
void pop();
void display();
int main(){
    int ch;
    while(1){
        printf("1.insert\t2.dele\t3.display\t4.exit\nenter ur choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
        }
    }
    return 0;
}
void push(){
    struct node*newnode;
    int x;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the element");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=top;
    top=newnode;
    printf("inserte sucessfully\n");
}
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        printf("Deleted element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;
        printf("Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
