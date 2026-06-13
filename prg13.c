#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int priority(char ch){
    if(ch=='('||ch=='#'){
        return 1;
    }if(ch=='+'||ch=='-'){
        return 2;
    }if(ch=='*'||ch=='/'){
        return 3;
    }
    if(ch=='^'||ch=='$'){
        return 4;
    }
    return 0;
}

int main(){
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char ch;
    push('#');
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for(i=0;infix[i]!='\0';i++){
        ch = infix[i];

        if (isalnum(ch))   // Operand
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        else   // Operator
        {
            while (priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while(stack[top] != '#'){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("corresponding postfix=%s\n",postfix);
    return 0;
} 
 
