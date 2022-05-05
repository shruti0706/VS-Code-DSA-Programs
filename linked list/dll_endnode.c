//program to insert a node at any position in double linked list 
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
    struct node *head,*node1, *fnode, *ptr,*new;
    int n, i,p;
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
    if (head == NULL)
        printf("empty list");
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            printf("%d->", ptr->num);
            ptr = ptr->next;
        }
        printf("%d", ptr->num);
    }
  printf("\n\n");

    printf("Enter the data for new node:\n");
    new=malloc(sizeof(struct node));
    if(new==NULL) printf("cant allocate memory");
    else{
        scanf("%d",&new->num);
       
            new->next=NULL;
            new->prev=fnode;
            ptr=head;
            while (ptr->next!=NULL)
            
                ptr=ptr->next;
            
            ptr->next=new;
            
        
    }
      printf("\nthe given list after inserting a new node is\n");
    if (head == NULL)
        printf("empty list");
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            printf("%d->", ptr->num);
            ptr = ptr->next;
        }
        printf("%d", ptr->num);
    }
    
    
    
    
    
    return 0;
}