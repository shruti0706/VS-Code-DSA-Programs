//program to create a node in circular double linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
    struct node *prev;
};

int main()
{
    struct node *node1;
    printf("enter data for a node");
    node1 = malloc(sizeof(struct node));
    scanf("%d", &node1->num);
    node1->next = node1;
    node1->prev = node1;
    if (node1 == NULL)
        printf("cant allocate memory");
    else

        printf("%d", node1->num);

    return 0;
}