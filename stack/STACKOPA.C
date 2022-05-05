//Stack operations implementation through Array
#include <stdio.h>
#define size 10;
int stack[10];
int top = -1;
void checkOverflow()
{
    if (top == 9)
    {
        printf("stack is full");
        exit(1);
    }
    
}
void checkUnderflow()
{
    if (top == -1)
    {
        printf("Empty stack");
        exit(1);
    }
}
void push(int data)
{
    checkOverflow();
    stack[++top] = data;
}
void pop()
{
    checkUnderflow();
    top--;
}
void peek()
{
    checkUnderflow();
    printf("Data at top is %d", stack[top]);
}
void printstack()
{
    int temptop = top;
    checkUnderflow();
    while (temptop != -1)
    {
        printf("%d\n", stack[temptop--]);
    }
}
void reverse()
{
    int t, scopy1[10], c = 0, scopy2[10];
    checkUnderflow();
    t = top;
    while (t != -1)
    {
        scopy1[c++] = stack[t--];
    }
    t = top;
    c = 0;
    while (t != -1)
    {
        scopy2[c++] = scopy1[t--];
    }
    t = top;
    c = 0;
    while (t != -1)
    {
        stack[c++] = scopy2[t--];
    }
printf("Stack reversed successfully");
}
int main()
{
    int choice, data, t;
clrscr();
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.print Stack\n5.Reverse Stack\n6.Exit\nEnter your choice-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("Element popped is %d", stack[top]);
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printstack();
            break;
        case 5:
            reverse();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nenter valid choice");
            break;
        }
    }
    getch();
    return 0;
}
