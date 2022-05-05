//program to create n node in circular linked list
#include <stdlib.h>
#include <stdio.h>
struct node
{
    int num;
    struct node *next;
};

int main()
{
    struct node *head, *node1, *ptr, *fnode;
    int i, n;
    printf("enter number of nodes");
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
    for (i = 2; i <= n; i++)
    {
        fnode = malloc(sizeof(struct node));
        if (fnode == NULL)
            printf("memory can not be allocated");
        else
        {
            printf("enter value for node%d\n", i);
            scanf("%d", &fnode->num);
            fnode->next = head;
            ptr->next = fnode;
            ptr = fnode;
        }
    }
    printf("data entered in the list is");
    if(head==NULL) printf("cant allocate memory");
    else{
        ptr=head;
        while(ptr!=fnode){
            printf("%d->",ptr->num);
            ptr=ptr->next;
        }
        printf("%d",fnode->num);
    }

    return 0;
}