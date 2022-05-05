//program of circular linklist of n nodes

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

int main()
{
    int n,i;
    struct node *head,*node1,*temp,*last;
    
    printf("Enter the number of nodes :");
    scanf("%d",&n);

    head=malloc(sizeof(struct node));
    if (head==NULL) 
    printf("Memory can'nt be allocated");
    else
    {
        printf("Enter the value of first node:");
        scanf("%d", &head->data);
        head->link=head;
        last=head->link;
    }
         temp=head;
    for(i=2;i<=n;i++)
    {
        printf("Enter the value of %d node :", i);
        node1=malloc(sizeof(struct node));
        if (node1==NULL) printf("Memory can'nt be allocated");
        else
        {
            scanf("%d", &node1->data);
            node1->link=head;
            temp->link=node1;
            last=node1;
             
             temp=node1;
        }
        
    }

    printf("The element in nodes is:\n");
    temp=head;
    if(head==NULL) printf("Link list is empty");
    else
    {
        
      while(temp!=last)
          {
              printf("%d->",temp->data);
               temp=temp->link;
          }
         printf("%d", last->data);
    }
    
}