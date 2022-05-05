//to find middle element in a circular double linked list
#include <stdio.h>
#include <stdlib.h>

//creating structure of linked list
struct list
{
    struct list *prev;
    int data;
    struct list *next;
} *start = NULL, *current = NULL;

//declaring functions
int create_node();
int add_data( struct list *temp);
void link_NodeatEnd(struct list *temp);
void print_list();
void middle_data();

int main()
{
    struct list *ptr;
    struct list *temp, *t1;
    int choice, ch;
    clrscr();

    while (1)
    {
        printf("\n1.Add data\n2.Show data\n3.middle data\n4.Exit\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t1 = create_node();
            add_data( t1);
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
int create_node()
{
    struct list *temp;
    temp = (struct list *)malloc(sizeof(struct list));
    return temp;
}

int add_data( struct list *temp)
{

      temp->next = temp;
        temp->prev = temp;
    
   
    
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
        temp->prev = current;
        temp->next = start;
        current->next = temp;
        current = temp;
        start->prev = current;
    }
}

void print_list()
{
    struct list *temp;
    temp = start;
    if (temp == NULL)
    {
        printf("list is empty..");
    }
    else
    {
        printf("\nthe entered list is : \n");

        while (temp->next != start)
        {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" %d ", temp->data);
    }
}
void middle_data()
{
    struct list *ptr1, *ptr2;
    ptr1 = start;
    ptr2 = start->next;
    current->next=NULL;
    
    while (ptr2 != NULL)
    {
        ptr1 = ptr1->next;
            if(ptr2->next==NULL)
        ptr2->next->next=NULL;
        ptr2 = ptr2->next->next;
    }
    printf("Middle Element is %d", ptr1->data);
}
