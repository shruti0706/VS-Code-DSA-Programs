//removing duplicate elements from sorted linked list
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
void removeDuplicate();

int main()
{
    int choice;
    clrscr();

    while (1)
    {
        printf("\n1.Add data in sorted order\n2.print list\n3.Remove Duplicate data \n4.Exit\nEnter your choice : ");
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
            removeDuplicate();
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
void removeDuplicate()
{
    struct list *p1, *p2, *p;
    p1 = start;
p2=p1->next;
    while (p2 != NULL)
    {
        if (p1->data == p2->data)
        {
            p = p2;
            p1->next = p2->next;
            //p=p2;
            p2 = p2->next;//->next;
            free(p);
           // p1 = p1->next;
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
   
    printf("\nduplicate data removed successfully");
}