//Reverse stack using recursion
#include <stdio.h>
#define size 10;
int stack[10];
int top = -1;
void checkOverflow()
{
    if (top == 9)
    
       return 1;
       return 0;
    
}
int checkUnderflow()
{
    if (top == -1)
    
      return 1;
    
    return 0;
}
void push(int data)
{     checkOverflow();
    stack[++top] = data;
}
int pop()
{
    checkUnderflow();
    return stack[top--];
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

void insertatbottom(int data)
{
    int temp;
    if (checkUnderflow())
    {
        push(data);
    }
    else
    {
        temp = pop();
        insertatbottom(data);
        push(temp);
    }
}
void reverse()
{
    int t;
    if (!checkUnderflow())
    {
        t = pop();
        reverse();
        insertatbottom(t);
    }
}

int main()
{
    int choice, data, t;
    clrscr();
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.print Stack\n 4 .insert at bottom\n5.Reverse Stack\n6.Exit\nEnter your choice-");
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
           // pop();
            break;
        case 3:
            printstack();
            break;
         case 4:   
            printf("Enter data");
            scanf("%d", &data);
            insertatbottom(data);
        break;
        case 5:
            reverse();
            printf("Stack reversed successfully");
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
