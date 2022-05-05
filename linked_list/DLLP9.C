// Sorted merge for 2 double linked lists
#include <stdio.h>
#include <stdlib.h>
// structure for first list
typedef struct list1
{
    struct list1 *prev;
    int data;
    struct list1 *next;
} list1;
//structure for number to be added in list
typedef struct list2
{
    struct list2 *prev;
    int data;
    struct list2 *next;
} list2;
//structure for storing merged list
typedef struct merge
{
    struct merge *prev;
    int data;
    struct merge *next;

} merge;

//declaring functions
list1 *add_data_list1();
list2 *add_data_list2();
int print_list1(struct list1 *h1);
int print_list2(struct list2 *h2);
merge *Merge(int c1, int c2, struct list1 *h1, struct list2 *h2);
void printMergedlist(struct merge *h);

int main()
{
     list1 *head1;
     list2 *head2;
     merge *head;
    int count1, count2;
   clrscr();

    head1 = add_data_list1();
    count1 = print_list1(head1);
    head2 = add_data_list2();
    count2 = print_list2(head2);
    head = Merge(count1, count2, head1, head2);

    printMergedlist(head);
   getch();

    return 0;
}
list1 *add_data_list1()
{
    list1 *temp1, *head1 = NULL, *current1=NULL;
    int i, n;
    printf("\nEnter total number of elements : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        temp1 = (list1 *)malloc(sizeof(list1));
        printf("\nEnter data %d in sorted order : ", i);
        scanf("%d", &temp1->data);
        temp1->next = NULL;
        temp1->prev = NULL;
        if (head1 == NULL)
        {
            head1 = temp1;
        }
        else
        {
            current1 = head1;
            while (current1->next != NULL)
                current1 = current1->next;
            current1->next = temp1;
            temp1->prev = current1;
        }
    }
    return head1;
}
int print_list1(struct list1 *h1)
{
    list1 *temp1;
    int count1 = 0;
    temp1 = h1;
    //  printf("\nhead1 is  %d", h1->data);
    if (temp1 == NULL)
    {
        printf("list is empty..");
    }
    else
    {
        printf("\nthe entered list is : \n");
        while (temp1 != NULL)
        {
            printf(" %d->", temp1->data);
            temp1 = temp1->next;
            count1++;
        }
    }
    return count1;
}
list2 *add_data_list2()
{
    list2 *temp2, *head2 = NULL, *current2=NULL;
    int i, n;
    printf("\nEnter total number of elements : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        temp2 = (list2 *)malloc(sizeof(list2));
        printf("\nEnter data %d in sorted order : ", i);
        scanf("%d", &temp2->data);
        fflush(stdin);
        temp2->next = NULL;
        temp2->prev = NULL;
        if (head2 == NULL)
        {
            head2 = temp2;
        }
        else
        {
            current2 = head2;
            while (current2->next != NULL)
                current2 = current2->next;
            current2->next = temp2;
            temp2->prev = current2;
        }
    }
    return head2;
}
int print_list2(struct list2 *h2)
{
    list2 *temp2;
    int count2 = 0;
    temp2 = h2;
    //  printf("\nhead2 is  %d", h2->data);
    if (temp2 == NULL)
    {
        printf("list is empty..");
    }
    else
    {
        printf("\nthe entered list is : \n");
        while (temp2 != NULL)
        {
            printf(" %d ->", temp2->data);
            temp2 = temp2->next;
            count2++;
        }
    }
    return count2;
}

merge *Merge(int c1, int c2, struct list1 *h1, struct list2 *h2)
{
    int d;
    list1 *t1;
    list2 *t2;
    merge *t, *head = NULL, *current = NULL;
    t1 = h1;
    t2 = h2;
    while (t1 != NULL || t2 != NULL)
    {
        t = (merge *)malloc(sizeof(merge));
        if (t1->data == t2->data)
        {
            t->data = t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1 == NULL)
        {
            t->data = t2->data;
            t2 = t2->next;
        }
        else if (t2 == NULL)
        {
            t->data = t1->data;
            t1 = t1->next;
        }
        else
        {
            d = t1->data < t2->data ? 1 : 2;
            if (d == 1)
            {
                t->data = t1->data;
                t1 = t1->next;
            }
            if (d == 2)
            {
                t->data = t2->data;
                t2 = t2->next;
            }
        }

        t->prev = NULL;
        t->next = NULL;
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = t;
            t->prev = current;
        }
    }

    return head;
}

void printMergedlist(struct merge *h)
{
    merge *temp;
    if (h == NULL)
        printf("empty list");
    temp = h;
    printf("\nMerged list in sorted order :\n ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}