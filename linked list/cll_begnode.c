//program to create a node at beginning in circular linked list

#include <stdlib.h>
#include <stdio.h>
struct node
{
    int num;
    struct node *link;
};

int main()
{
    struct node *head, *node1, *temp, *node2, *new;
    int i, n, data;
    printf("enter number of nodes");
    scanf("%d", &n);
    node1 = malloc(sizeof(struct node));
    if (node1 == NULL)
        printf("memory is not allocated");
    else
    {
        printf("enter data for node1\n");
        scanf("%d", &node1->num);
        node1->link = node1;
        head = node1;
        node2 = head->link;
        temp = head;
    }
    for (i = 2; i <= n; i++)
    {
        node2 = malloc(sizeof(struct node));
        if (node2 == NULL)
            printf("memory can not be allocated");
        else
        {
            printf("enter value for node%d\n", i);
            scanf("%d", &node2->num);
            node2->link = head;
            temp->link = node2;
            temp = node2;
        }
    }
    printf("data entered in the list is");
    if (head == NULL)
        printf("cant allocate memory");
    else
    {
        temp = head;
        while (temp != node2)
        {
            printf("%d->", temp->num);
            temp = temp->link;
        }
        printf("%d", node2->num);
    }

    printf("\n\n");
    printf("Enter the data for new node:\n");
    scanf("%d", &data);
    new = malloc(sizeof(struct node));
    if (node1 == NULL)
        printf("Memory can't be allocated");
    else
    {
        new->num = data;
        temp = new;
        temp->link = head;
        head = new;
    }
    printf("list after inserting new node:\n");
    if (head == NULL)
        printf("Link list is empty");
    else
    {
        temp = head;
        while (temp != node2)
        {
            printf("%d->", temp->num);
            temp = temp->link;
        }
        printf("%d", node2->num);
    }

    return 0;
}