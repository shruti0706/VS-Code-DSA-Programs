//Reverse every K elements of circular linked list
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
struct list *reverse(struct list *start, int k);
int main()
{
    int k;
    int choice;
    clrscr();

    while (1)
    {
        printf("\n1.Add data in sorted order\n2.print list\n3.Reverse every K elements \n4.Exit\nEnter your choice : ");
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
            printf("enter value of k");
            scanf("%d", &k);
            current->next=NULL;
            start = reverse(start, k);
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
count++;
        temp = temp->next;
    while (temp != start)
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
        
        while (temp->next!= NULL)
        {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" %d ", temp->data);

        current = temp;
        current->next=start;
    }
}
struct list *reverse(struct list *start, int k)
{

    struct list *cur = start, *prev = NULL, *temp = NULL;
    int count = 0;
    while (cur != NULL && count < k)

    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        count++;
    }
    if (temp != NULL)
    {
        start->next = reverse(temp, k);
    }
    return prev;
}
