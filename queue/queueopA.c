//Queue operations using  Array
#include <stdio.h>
int queue[10];
int front = 0, rear = -1;
int enqueue(int data)
{
    isFull();
    queue[++rear] = data;
    return 0;
}
int dequeue()
{
    int f, i;
    isEmpty();
    f = queue[front];
    for (i = 0; i <= rear; i++)
    {
        queue[i] = queue[i + 1];
    }
    rear--;
    return f;
}
void isEmpty()
{
    if (front == 0 && rear == -1)
    {
        printf("Queue is empty");
        exit(0);
    }
}
void isFull()
{
    if (rear == 9)
    {
        printf("Queue is full");
        exit(0);
    }
}
int frontElement()
{
    isEmpty();
    printf("\ndata at front is %d\n", queue[front]);
    return 0;
}
void printAll()
{
    int i;
    isEmpty();
    printf("\nElements of queue are : \n");
    for (i = 0; i < rear; i++)
    {
        printf("%d <- ", queue[i]);
    }
    printf("%d \n", queue[i]);
}
int reverse()
{
    int i;
    int rev[10];
    for (i = 0; i <= rear; i++)
    {
        rev[i] = queue[rear - i];
    }
    for (i = 0; i <= rear; i++)
    {
        queue[i] = rev[i];
    }
    printf("\nQueue reversed Successfully...\n");
    return 0;
}
int main()
{
    int choice, data, f;
    clrscr();
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Element at front\n4.print Queue\n5.Reverse Queue\n6.Exit\nEnter your choice-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            f = dequeue();
            printf("\nElement dequeued is %d\n", f);
            break;
        case 3:
            frontElement();
            break;
        case 4:
            printAll();
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