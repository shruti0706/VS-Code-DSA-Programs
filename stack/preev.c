// prefix evaluation
#include<stdio.h>
int stack[20];
int top = -1;

int overflow()
{
    if (top == 20)
    
        printf("stack full");
        return 0;
    
}

void push(int opt)
{
    overflow();
    stack[++top] = opt;
}

int underflow()
{
    if (top == -1)
        return -1;
}

int pop()
{
    underflow();
    return (stack[top--]);
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

int main(){
    int i=0,j,n,x,a,b,result,length;
    char p[50],q[50];

clrscr();
    printf("Enter the prefix expression- ");
    gets(q);

    length=0;
    while (q[i] != '\0')
    {
        length++;
        i++;
    }
    j=0;
    for (i = length - 1; i >= 0; i--,j++)
    {
        p[j] = q[i];
    }
    // printf("\npostf %s\n",p);
i=0;
while(p[i]!='\0'){

    if(isOperand(p[i])){
        printf("\nEnter value of %c- ",p[i]);
        scanf("%d",&n);
        push(n);
    }
    if(isOperator(p[i])){
        a=pop();
        b=pop();
        if(p[i]=='+')
        result=b+a;
        if(p[i]=='-')
        result=b-a;
        if(p[i]=='*')
        result=b*a;
        if(p[i]=='/')
        result=b/a;

        push(result);
    }
    i++;
}

printf("Answer- %d",stack[top]);
getch();
return 0;


}