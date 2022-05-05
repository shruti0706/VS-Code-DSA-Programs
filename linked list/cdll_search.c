//to create n nodes in circular double linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *prev;
    struct node *next;
};
int main()
{
    struct node *head,*node1, *fnode, *ptr;
    int n, i,count;
    printf("enter no of nodes");
    scanf("%d", &n);
    head = malloc(sizeof(struct node));
    if (head == NULL)
        printf("memory cannot be allocated");
  node1 = malloc(sizeof(struct node));
    if (node1 == NULL)
        printf("memory cannot be allocated");
    else
    {
        printf("\nenter value for node 1");
        scanf("%d", &node1->num);
        node1->prev = NULL;
        node1->next = fnode;
        head=node1;
        ptr = head;

        for (i = 2; i <= n; i++)
        {
            fnode = malloc(sizeof(struct node));
            if (fnode == NULL)
                printf("memory can't be allocated ");
            else
            {
                printf("\nenter value for node %d ", i);
                scanf("%d", &fnode->num);
                fnode->prev = ptr;
                fnode->next = node1;
                ptr->next = fnode;
                ptr = ptr->next;
                
            }
        }
        node1->prev=fnode;
    }
    printf("\nthe given list is\n");
    if (head == NULL)
        printf("empty list");
    else
    {
        ptr = head;
        while (ptr != fnode)
        {
            printf("%d->", ptr->num);
            ptr = ptr->next;
        }
        printf("%d", ptr->num);
    }
    printf("enter the data which u wnt to search");
    scanf("%d", &i);

    if (head == NULL)
        printf("list is empty");
    else
    {
        ptr = head;
        count = 1;
        while (ptr->num != i)
        {
            ptr = ptr->next;
            count++;
        }
    }

    printf("data present at %d location", count);

    return 0;
}