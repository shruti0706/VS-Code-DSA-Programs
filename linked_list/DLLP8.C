// Add a number to a double linked list
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
//structure for storing sum
typedef struct sum
{
    struct sum *prev;
    int data;
    struct sum *next;

} sum;

list1 *add_data_list1();
list2 *add_data_list2();
int print_list1(struct list1 *h1);
int print_list2(struct list2 *h2);
sum *Add(int c1, int c2, struct list1 *h1, struct list2 *h2);
list1 *reverse_list1(struct list1 *h1);
sum * reverse_sum(struct sum *h);
void printSum(struct sum *h);

int main()
{
    struct list1 *head1;
    struct list2 *head2;
    struct sum *head;
    int count1, count2;
    clrscr();

    head1 = add_data_list1();
    count1 = print_list1(head1);
    head1 = reverse_list1(head1);


    head2 = add_data_list2();
    count2 = print_list2(head2);
    head = Add(count1, count2, head1, head2);
   
   head= reverse_sum(head);
    printSum(head);
    getch();

    return 0;
}
list1 *add_data_list1()
{
    list1 *temp1, *head1 = NULL, *current1;
    int i, n;
    printf("\nEnter total number of digits : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        temp1 = (list1 *)malloc(sizeof(list1));
        printf("\nEnter single digit : ");
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
            printf(" %d", temp1->data);
            temp1 = temp1->next;
            count1++;
        }
    }
    return count1;
}
list2 *add_data_list2()
{
    list2 *temp2, *head2 = NULL, *current2 = NULL;
    int i = 1, n, num, ld;
    printf("\nEnter number to be added in list : ");
    scanf("%d", &n);
    num = n;
    while (n != 0)
    {
        temp2 = (list2 *)malloc(sizeof(list2));
        ld = n % 10;
        temp2->data = ld;
        n = n / 10;
        temp2->prev = NULL;
        temp2->next = NULL;
        if (head2 == NULL)
        {
            head2 = current2 = temp2;
        }
        else
        {

            current2->next = temp2;
            temp2->prev = current2;
            current2 = temp2;
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

        while (temp2 != NULL)
        {
            //   printf(" %d ->", temp2->data);
            temp2 = temp2->next;
            count2++;
        }
    }
    return count2;
}
list1 *reverse_list1(struct list1 *h1)
{
    struct list1 *temp, *ptr, *ahead;
    temp = h1;
    ahead = h1;
    if (h1->next == NULL)
        return h1;

    while (ahead->next != NULL)
    {
        ahead = ahead->next;
        ptr = temp->next;
        temp->next = temp->prev;
        temp->prev = ptr;
        temp = ahead;
    }
    ahead->next = ahead->prev;
    ahead->prev = NULL;
    h1 = ahead;

    return h1;
}
sum *Add(int c1, int c2, struct list1 *h1, struct list2 *h2)
{

    int carry = 0, s, i;
    list1 *t1;
    list2 *t2;
    sum *t, *head = NULL, *current = NULL;

    t1 = h1;
    t2 = h2;
    i = c1 > c2 ? c1 : c2;
    while (i--)
    {
        if (t1 == NULL)
        {
            t1->data = 0;
        }

        if (t2 == NULL)
        {
            t2->data = 0;
        }
        t = (sum *)malloc(sizeof(sum));
        s = t1->data + t2->data + carry;
        if ((s / 10) != 0)
        {
            s = s % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        t->data = s;
        t->prev = NULL;
        t->next = NULL;
        t1 = t1->next;
        t2 = t2->next;
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
sum * reverse_sum(struct sum *h){
      struct sum *temp, *ptr, *ahead;
    temp = h;
    ahead = h;
    if (h->next == NULL)
        return h;

    while (ahead->next != NULL)
    {
        ahead = ahead->next;
        ptr = temp->next;
        temp->next = temp->prev;
        temp->prev = ptr;
        temp = ahead;
    }
    ahead->next = ahead->prev;
    ahead->prev = NULL;
    h = ahead;

    return h;
}
void printSum(struct sum *h){
  sum *temp;
  if (h == NULL)
    printf("empty list");
  temp = h;
  while (temp != NULL)
  {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("\n");


}