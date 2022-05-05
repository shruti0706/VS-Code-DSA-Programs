//to add a new node in circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
int main()
{
    struct node *head,*node1, *fnode, *last, *new, *ptr;
    int n, i, p;
    printf("enter number of nodes ");
    scanf("%d", &n);
     node1 = malloc(sizeof(struct node));
    if (node1 == NULL)
        printf("memory is not allocated");
    else
    {
        printf("enter data for node1\n");
        scanf("%d", &node1->num);
        node1->next = node1;
        head = node1;
        fnode = head->next;
        ptr = head;
    }
    ptr = head;
    for (i = 2; i <= n; i++)
    {
        fnode = malloc(sizeof(struct node));
        if (fnode == NULL)
            printf("cant allocate memory");
        else
        {
            printf("enter value for node %d\n", i);
            scanf("%d", &fnode->num);
            fnode->next = head;
            ptr->next = fnode;
            last = fnode;
            ptr = fnode;
        }
    }
    printf("the data entered in the list \n\n");
    ptr = head;
    if (head == NULL)
        printf("empty list");
    else
    {
        while (ptr != last)
        {
            printf("%d->", ptr->num);
            ptr = ptr->next;
        }
        printf("%d", last->num);
    }
    printf("\nenter the position for new node");
    scanf("%d", &p);
    printf("\nenter value for new node");
    
    ptr = head;
    new = malloc(sizeof(struct node));
    if (new == NULL)
        printf("cant allocate memory");
    else{
scanf("%d", &new->num);
     if (p == 1)
    {
        new->next = head;
        last->next = new;
        head = new;
    }
    else if (p == n + 1)
    {
        new->next = head;
        last->next = new;
        last = new;
    }
    else
    {
        for (i = 1; i < p - 1; i++)
            ptr = ptr->next;
        new->next = ptr->next;
        ptr->next = new;
    }
    }

printf("\nfinal list:");
ptr = head;
if (head == NULL)
    printf("empty list");
else
{
    while (ptr != last)
    {
        printf("%d->", ptr->num);
        ptr = ptr->next;
    }
    printf("%d", last->num);
}

return 0;
}