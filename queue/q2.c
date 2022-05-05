// Queue operations using linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} q;
q *front = NULL, *rear = NULL;
typedef struct priorityqueue
{
    int data;
    struct queue *next;
} pq;
pq *head = NULL, *cur = NULL;
int enqueue(int data)
{
    q *temp;

    temp = (q *)malloc(sizeof(q));
    isFull(temp);
    temp->data = data;
    temp->next = NULL;
    if (front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
    return 0;
}
q *dequeue()
{
    q *p;
    isEmpty();
    p = front;
    front = front->next;
    return p;
}
int isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty");
        exit(0);
    }
}
int isFull(q *temp)
{
    if (temp == NULL)
    {
        printf("Queue is full");
        exit(0);
    }
}
int frontElement()
{
    isEmpty();
    printf("data at front is %d", front->data);
    return 0;
}
void printAll()
{
    q *temp = front;
    isEmpty();
    printf("\nElements of queue are : \n");
    while (temp->next != NULL)
    {
        printf(" %d <-", temp->data);
        temp = temp->next;
    }
    printf(" %d ", temp->data);
}
int priorityqueue()
{
    q *qtemp,*qprev;
    int total,i,data;
    printAll();
    printf("enter total number of elements to be prioritize : ");
    scanf("%d",&total);
    for(i=1;i<=total;i++){
          printf("enter %d element ");
          scanf("%d",&data);




    }
}

int main()
{
    q *p;
    int choice, data;
    clrscr();
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Element at front\n4.print Queue\n5.Prioritize Queue\n6.Exit\nEnter your choice-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            p = dequeue();
            printf("\nElement dequeued is %d\n", p->data);
            free(p);
            break;
        case 3:
            frontElement();
            break;
        case 4:
            printAll();
            break;
        case 5:
            priority();
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
