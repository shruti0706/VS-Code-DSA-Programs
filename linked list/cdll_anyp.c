//to add a node in circular double linked list
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
    printf("enter the position where you want to add a node");
    scanf("%d",&p);
    printf("enter the value for new node");
    new=malloc(sizeof(struct node));
    if(new==NULL) printf("cant allocate memory");
    else{
        scanf("%d",&new->num);
        if(p==1){
            new->next=head;
            new->prev=fnode;
            head->prev=new;
            fnode->next=new;
            head=new;
            ptr=new;
        }
        else if(p==n) {
            new->next=head;
            new->prev=fnode;
            ptr=head;
            while (ptr!=fnode)             
                ptr=ptr->next;
            
            ptr->next=new;
        }
        else{
            ptr=head;
            for(i=1;i<=p-1;i++)
                ptr=ptr->next;
           new->next=ptr;
           ptr->prev=new;
           ptr=head;
           for(i=1;i<=p-2;i++)
           ptr=ptr->next;
           new->prev=ptr;
           ptr->next=new;     
        }
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