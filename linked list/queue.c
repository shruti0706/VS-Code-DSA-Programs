//queue using array
#include <stdio.h>

int main()
{
    int n, front, rear, value, i, op;
    printf("Enter The size of queue : ");
    scanf("%d", &n);
    //n=n-1;
    int queue[n];
    front = 0;
    rear = 0;

    printf("\n1.insertion\n2.deletion\n3. printing queue\n4. quit \n");

    while (op != 4)
    {
        printf("Choice : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:

            if (rear == n)
                printf(" queue is already Full!!\n");
            else
            {
                printf("Enter The Value you want to insert : ");
                scanf("%d", &value);
                queue[rear] = value;
                rear++;
            }
            break;

        case 2:

            if (front == rear)
                printf("queue is already Empty!!\n");
            else
            {
                for (i = front; i < rear; i++)
                {
                    queue[i] = queue[i + 1];
                }
                
                rear--;
            }
            break;

        case 3:
            if (front == rear)
                printf(" queue is Empty!!\n");
            else
            {
                for (i = front; i <= rear - 1; i++) //n=n-1
                {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            break;
        default:
            printf(" Enter Valid Choice \n");
            break;
        }
    }
}