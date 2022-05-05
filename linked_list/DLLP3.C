//removing duplicate elements from sorted linked list
#include <stdio.h>
#include <stdlib.h>

//creating structure of linked list
struct list
{
    struct list *prev;
    int data;
    struct list *next;
};

//declaring functions
struct list *create_node();
int count_node(struct list *head);
struct list *add_data(int choic, struct list *temp, struct list *head);
struct list *link_NodeatEnd(struct list *temp, struct list *head);
void print_list(struct list *head);
void removeDuplicate(struct list *head);

int main()
{
    struct list *ptr, *head;
    struct list *temp, *t1;
    int choice, ch;

    //  clrscr();
    head = NULL;
    while (1)
    {
        printf("\n1.Add data\n2.Show data\n3.Remove Duplicate data\n4.Exit\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t1 = create_node();
            temp = add_data(choice, t1, head);
            head = link_NodeatEnd(temp, head);
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            removeDuplicate(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
            break;
        }
    }
    //  getch();
    return 0;
}
struct list *create_node() //allocates memory to new node and give its address to adddata()
{
    struct list *temp;
    temp = (struct list *)malloc(sizeof(struct list));
    return temp;
}
struct list *add_data(int choic, struct list *temp, struct list *head)
{
    int position, i = 1;
    int count = count_node(head);

    if (choic == 1)
    {
        // struct list *temp;
        // temp = create_node();
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        printf("Enter the position of data you want to update");
        scanf("%d", &position);
        if (position > count)
        {
            printf("enter valid position");
            return 0;
        }
        temp = head;
        while (i != position)
        {
            temp = temp->next;
            i++;
        }
    }

    printf("\nEnter data -");
    scanf("%d", &temp->data);
    if (position == 1)
        head->data = temp->data;

    return temp;
}

struct list *link_NodeatEnd(struct list *temp, struct list *head)
{
    struct list *current;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
        temp->prev = current;
    }
    return head;
}
void print_list(struct list *head)
{
    struct list *temp;
    temp = head;
    printf("\nhead is  %d", head->data);
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
        //current=temp;
    }
}
int count_node(struct list *head)
{
    int count = 0;
    struct list *temp;
    temp = head;

    while (temp != NULL)
    {
        count++;

		temp = temp->next;
    }
    return count;
}
void removeDuplicate(struct list *head)
{
    struct list *ptr1 = head;
    while (ptr1->next != NULL)
    {
        if (ptr1->data == ptr1->next->data)
        {
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            ptr1->prev = ptr1->prev->prev;
            ptr1 = ptr1->prev;

	printf("ptr1=%d",ptr1->data);
	}
	else
	ptr1 = ptr1->next;
    }
    printf("\nduplicate data removed successfully");
}