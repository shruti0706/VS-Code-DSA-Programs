//to find middle element in a single linked list
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
} *start = NULL, *current = NULL;

int create_node();
int add_data();
void link_NodeatEnd(struct list *temp);
void print_list();
void middle_data();
int main()
{
    int choice;
    clrscr();
    while (1)
    {
        printf("\n1.Add data\n2.print list\n3.middle data\n4.Exit\nEnter your choice : ");
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
            middle_data();
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
    //    return temp;
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
void middle_data()
{
    struct list *ptr1, *ptr2;
    ptr1 = start;
    ptr2 = start->next;
    while (ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    printf("Middle Element is %d", ptr1->data);
}