// infix to prefix
  
#include <stdio.h>
#include <conio.h>

int stack[20];
int top = -1;

int overflow()
{
    if (top == 20)

        printf("stack full");
    return 0;
}

void push(char opt)
{
    overflow();
    stack[++top] = opt;
}

int underflow()
{
    if (top == -1)
        return -1;
}

char pop()
{
    underflow();
    return (stack[top--]);
}

int priority(char symbol)
{

    switch (symbol)
    {
    case '*':
    case '/':
        return 2;
        break;

    case '-':
    case '+':
        return 1;
        break;

    case '(':
        return 0;
        break;

    default:
        return -1;
    }
}
int isOperator(char op)
{
    if (op == '+' || op == '/' || op == '*' || op == '-')
    {
        return 1;
    }
    return 0;
}

int isOperand(char op)
{
    if ((op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // q=Infix expression , post= Postfix expression
    int i = 0, j = 0, length = 0;
    char t;
    char q[50], post[50], r[50],pre[50];
    clrscr();
    printf("Enter the expression- ");
    gets(r);
    while (r[i] != '\0')
    {
        length++;
        i++;
    }
    for (i = length - 1; i >= 0; i--,j++)
    {
        q[j] = r[i];
    }
    push('(');
    i = 0;
    j = 0;
    while (q[i] != '\0')
    {

        if (isOperand(q[i]))
        {
            post[j++] = q[i];
        }
        if (q[i] == '(')
        {
            push(q[i]);
        }
        if (isOperator(q[i]))
        {
            while (priority(stack[top]) >= priority(q[i]))
            {
                post[j++] = pop();
            }

            push(q[i]);
        }
        if (q[i] == ')')
        {
            while (stack[top] != '(')
                post[j++] = pop();
            t = pop();
        }
        i++;
    }
    while (stack[top] != '(')
        post[j++] = pop();
    post[j] = '\0';
     printf("\npostfix expression is- %s\n",post);
    i=0;
    length=0;
    while (post[i] != '\0')
    {
        length++;
        i++;
    }
    j=0;
    for (i = length - 1; i >= 0; i--,j++)
    {
        pre[j] = post[i];
    }
       printf("\nprefix expression is- %s\n",pre);
    getch();
    return 0;
}
