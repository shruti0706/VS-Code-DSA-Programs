//removing duplicate elements from sorted single linked list
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
} *start = NULL, *current = NULL;

int create_node();
int count_node();
int add_data();
void link_NodeatEnd(struct list *temp);
void print_list();
void deleteNnodes();

int main()
{
    int choice;
    clrscr();

    while (1)
    {
        printf("\n1.Add data in sorted order\n2.print list\n3.Delete N nodes after every M nodes \n4.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_data();
            break;
        case 2:
            print_list();
            break;
        case 3:
            deleteNnodes();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("enter valid choice");
        }
    }
    getch();
    return 0;
}
int create_node()
{
    struct list *temp;
    temp = (struct list *)malloc(sizeof(struct list));
    return temp;
}
int add_data()
{
    struct list *temp;
    int position, i = 1;
    temp = create_node();
    temp->next = NULL;
    printf("\nEnter data -");
    scanf("%d", &temp->data);
    link_NodeatEnd(temp);
}
void link_NodeatEnd(struct list *temp)
{
    if (start == NULL)
    {
        start = current = temp;
    }
    else
    {
        current->next = temp;
        current = temp;
    }
}
int count_node()
{
    int count = 0;
    struct list *temp;
    temp = start;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void print_list()
{
    struct list *temp;
    temp = start;
    // printf("%d",count_node());
    if (temp == NULL)
    {
        printf("list is empty..");
    }
    else
    {
        printf("\nthe entered list is : \n");
        while (temp->next != NULL)
        {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" %d ", temp->data);
        current = temp;
    }
}
void deleteNnodes()
{
    int m, n, i = 1, j = 1;

    struct list *p1, *p2, *p;
    printf("Enter the value of M and N");
    scanf("%d%d", &m, &n);
   

    while (p2 != NULL)
    {
	i = 1;
	while (i <= m && p2 != NULL)
	{
        if(j==1){
             p1 = start;
              p2 = p1->next;
              i++;
              ++j;
        }
        else{
	    p1 = p1->next;
	    p2 = p2->next;
	    i++;
        }
        }
        i = 1;
        while (i <= n && p2 != NULL)
        {
            p = p2;
            p1->next = p2->next;
          
            p2 = p2->next; //->next;
            free(p);
            i++;
        //  p1 = p1->next;
        }
    }

    printf("\nData deleted successfully");
}