#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *top = NULL;

void checkOverflow(stack *temp)
{
    if (temp == NULL)
    {
        printf("stack Overflow");
        exit(0);
    }
}
void checkUnderflow()
{
    if (top == NULL)
    {
        printf("stack Underflow");
        exit(0);
    }
}
void push(int data)
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    checkOverflow(temp);
    temp->data = data;
    if (top != NULL)
        temp->next = top;
    top = temp;
}
stack *pop()
{
    stack *temp;
    checkUnderflow();
    temp = top;
    top = top->next;
    return temp;
}
void peek()
{
    printf("\ndata at top is %d", top->data);
}
void printstack()
{
    stack *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void reverse()
{
    stack *temp, *temp1 = NULL;
    while (top != NULL)
    {
        temp = (stack *)malloc(sizeof(stack));
        temp ->data= top->data;
        top = top->next;
        if (temp1 != NULL)
            temp->next = temp1;
        temp1 = temp;
    }
    top = temp1;
}

int main()
{
    stack *temp;
    int choice, data;
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

            temp = pop();
            printf("Element popped is %d", temp->data);
            free(temp);
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
