//to reverse double linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *prev;
    struct node *next;
};
void print_list();
int main()
{
    struct node *head,*node1, *fnode, *ptr;
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
        ptr=head;

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
                fnode->next = NULL;
                ptr->next = fnode;
                ptr = ptr->next;
            }
        }
    }
    printf("\nthe given list is\n");
   
  print_list(head);
    return 0;
}
void print_list(struct node *p){
    if(p){
        print_list(p->next);
        printf("%d->",p->num);
    }
}