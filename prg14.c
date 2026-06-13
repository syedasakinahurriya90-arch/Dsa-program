#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int prior(char ch){
    if (ch == ')'||ch=='#')
        return 1;
    if (ch == '+' || ch == '-')
        return 2;
    if (ch == '*' || ch == '/')
        return 3;
    if (ch == '^' || ch == '$')
        return 4;
    return 0;
}

int main(){
    char infix[50], prefix[50];
    int i, j = 0;

    push('#');

    printf("Enter Infix Expression: ");
    gets(infix);

    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        if (isalnum(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == ')')
        {
            push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (stack[top] != ')')
                prefix[j++] = pop();
            pop();
        }
        else
        {
            while (prior(stack[top]) > prior(infix[i]))
                prefix[j++] = pop();

            push(infix[i]);
        }
    }

    while (stack[top] != '#')
        prefix[j++] = pop();

    prefix[j] = '\0';

    strrev(prefix);

    printf("Prefix Expression = %s", prefix);

    return 0;
}