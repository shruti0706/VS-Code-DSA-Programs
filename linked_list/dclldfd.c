
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
int count_node();
int add_data(int choic, struct list *temp);
void link_NodeatEnd(struct list *temp);
void print_list();

int main()
{
    struct list *ptr;
    struct list *temp, *t1;
    int choice, ch;
    // clrscr();

    while (1)
    {
        printf("\n1.Add data\n2.Show data\n3. 4.Exit\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t1 = create_node();
            temp = add_data(choice, t1);
        case 2:
            print_list();
            break;
        case 3:

            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
            break;
        }
    }
    // getch();
    return 0;
}
int create_node()
{
    struct list *temp;
    temp = (struct list *)malloc(sizeof(struct list));
    return temp;
}

int add_data(int choic, struct list *temp)
{
    int position, i = 1;
    int count = count_node();

    if (choic == 1)
    {
        temp->next = temp;
        temp->prev = temp;
    }
    else
    {
        printf("Enter the position of data you want to update");
        scanf("%d", &position);
        if (position > count)
        {
            printf("enter valid position");
            return;
        }
        temp = start;
        while (i != position)
        {
            temp = temp->next;
            i++;
        }
    }
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
        current = temp;
    }
}
