//to delete a node in circular double linked list
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
    struct node *head, *node1,*fnode, *ptr, *p;
    int n, i;
    printf("enter no of nodes");
    scanf("%d", &n);
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
        while (ptr!=fnode)
        {
            printf("%d->", ptr->num);
            ptr = ptr->next;
        }
        printf("%d", ptr->num);
    }
    printf("\n\nenter the value of node which you want to delete");
    scanf("%d",&i);
    ptr=head;
    if(head==NULL) printf("cant allocate memory");
    else{
        while(ptr->num!=i){
            p=ptr;
            p->prev=ptr->prev;
            ptr=ptr->next;
        }
        p->next=ptr->next;
        free(ptr);
    }

     printf("\nthe final list is\n");
    if (head == NULL)
        printf("empty list");
    else
    {
        ptr = head;
        while (ptr!=fnode)
        {
            printf("%d->", ptr->num);
            ptr = ptr->next;
        }
        printf("%d", ptr->num);
    }



    return 0;
}