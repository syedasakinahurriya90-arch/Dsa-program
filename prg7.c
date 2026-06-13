#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *next;
};
struct list *head=NULL;
void insert();
void del();
void display();
int main(){
    int ch;
    while(1){
        printf("insertion\n2.del\n3.display\n4.exit\nenter ur choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert();
            break;
            case 2:del();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
        }
    }
    return 0;
} 
void insert(){
    int ele;
    printf("enter the element");
    scanf("%d",&ele);
    struct list *newnode,*temp;
    newnode=(struct list*)malloc(sizeof(struct list));
    newnode->data=ele;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("node inserted\n");
}

void del()
{
    struct list *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Deleted element: %d\n", temp->data);

    head = head->next;

    free(temp);
}
void display()
{
    struct list *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}