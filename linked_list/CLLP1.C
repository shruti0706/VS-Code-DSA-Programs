//to find middle element in a circular linked list
#include <stdio.h>
#include <stdlib.h>

//creating structure of linked list
struct list
{
    int data;
    struct list *next;
} *cur = NULL;

//declaring functions
struct list *create_node();
int count_node();
struct list *add_data(int choic, struct list *temp);
void link_Node(struct list *temp);
void print_list();
void middle_data()
{
    struct list *ptr1, *ptr2;
    ptr1 = cur->next;
    ptr2 = cur->next->next;
    while (ptr2 != cur->next)
    {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr2 == cur)
        {
            ptr1 = ptr1->next;
            break;
        }
    }
    printf("Middle Element is %d", ptr1->data);
}
int main()
{
    struct list *ptr;
    struct list *temp, *t1;
    int choice;
     clrscr();

    while (1)
    {
        printf("\n1.Add data\n2.Show data\n3.middle data\n4.Exit\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t1 = create_node();
            add_data(choice, t1);
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
            printf("Enter valid choice");
            break;
        }
    }
     getch();
    return 0;
}

struct list *create_node()
{
    struct list *temp;
    temp = (struct list *)malloc(sizeof(struct list));
    return temp;
}

struct list *add_data(int choic, struct list *temp)
{

    temp->next = temp;

    printf("\nEnter data -");
    scanf("%d", &temp->data);
    link_Node(temp);
}

void link_Node(struct list *temp)
{
    if (cur != NULL)
    {
        temp->next = cur->next;
        cur->next = temp;
    }
    cur = temp;
}

int count_node()
{
    int count = 0;
    struct list *temp, *head;
    head = temp = cur->next;

    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print_list()
{
    struct list *temp, *head;
    head = temp = cur->next;
    if (temp == NULL)
    {
        printf("list is empty..");
    }
    else
    {
        printf("\nthe entered list is : \n");
        while (temp->next != head)
        {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" %d ", temp->data);
        cur = temp;
    }
}