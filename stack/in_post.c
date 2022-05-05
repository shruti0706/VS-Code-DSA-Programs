// Infix to postfix conversion
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
    // q=Infix expression , p= Postfix expression
    int i, j, length = 0;
    char t;
    char q[50], p[50];
     clrscr();
    printf("Enter the expression- ");
    gets(q);
    push('(');
    
    i = 0;
    j = 0;
    while (q[i] != '\0')
    {

        if (isOperand(q[i]))
        {
            p[j++] = q[i];
        }
        if (q[i] == '(')
        {
            push(q[i]);
        }
        if (isOperator(q[i]))
        {
            while (priority(stack[top]) >= priority(q[i]))
            {
                 p[j++]  = pop();
             
            }

            push(q[i]);
        }
        if (q[i] == ')')
        {
            while(stack[top]!='(')
                p[j++] = pop();
                t = pop();

            
        }
        i++;
    }
   while(stack[top]!='(')
       p[j++]=pop();
       p[j]='\0';
       printf("postfix expression is- %s",p);


 getch();
return 0;
}
