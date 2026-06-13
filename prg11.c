#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10
void push();
void pop();
void peep();
void display();
int s[max];
int top=-1;
int main(){
    int ch;
    while(1){
        printf("1.push\n2.pop\n3.peep\n4.display\n5.exit\n");
        printf("enter ur choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peep();
            break;
            case 4:display(0);
            break;
            case 5:exit(0);
            break;
        }
    }

}
void push(){
    int data;
    if(top>=max-1){
        printf("stack is full\n");
    }
    else{
        printf("enter the element");
        scanf("%d",&data);
        top=top+1;
        s[top]=data;
        printf("the inserted element is %d\n",data);
    }

}
void pop(){
    int item;
    if(top==-1){
        printf("underflow\n");
    }
    else{
        item=s[top];
        top=top-1;
        printf("deleted %d\n",item);
    }
}
void peep(){
    if(top==-1){
        printf("underflow");
    }
    else{
        printf("topmost element %d\n",s[top]);
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\n",s[i]);
    }
}