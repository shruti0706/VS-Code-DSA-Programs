// Add a number to a circular linked list
#include <stdio.h>
#include <stdlib.h>

//creating structure of linked list
typedef struct list1
{
  int data;
  struct list1 *link;
} list1;
list1 *head1, *current1 = NULL;

//structure for number to be added in list
typedef struct list2
{
  int data;
  struct list2 *link;
} list2;
list2 *head2, *current2 = NULL;
typedef struct sum
{
  int data;
  struct sum *link;
} sum;
sum *head, *current;

//declaring functions
int add_data_list1();
int add_data_list2();
void print_list1();
void print_list2();
void Add(int c1, int c2);
void reverse_list1();
void reverse_sum();
void printSum();

int main()
{
  int count1, count2;
  clrscr();

  count1 = add_data_list1();
  print_list1();
  reverse_list1();
  count2 = add_data_list2();
  Add(count1, count2);
  reverse_sum();
  printSum();
  getch();
  return 0;
}
int add_data_list1()
{
  list1 *temp1;
  int i, n;
  printf("\nEnter total number of digits : ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    temp1 = (list1 *)malloc(sizeof(list1));
    printf("\nEnter single digit : ");
    scanf("%d", &temp1->data);
    temp1->link = NULL;
    if (head1 == NULL)
      head1 = current1 = temp1;
    else
    {
      current1->link = temp1;
      current1 = temp1;
    }
    current1->link = head1;
  }
  return n;
}

int add_data_list2()
{
  list2 *temp2;
  int i, n, num, ld, count2 = 0;
  printf("\nEnter number to be added in list : ");
  scanf("%d", &n);
  num = n;
  while (n != 0)
  {
    count2++;
    temp2 = (list2 *)malloc(sizeof(list2));
    ld = n % 10;
    temp2->data = ld;
    n = n / 10;

    temp2->link = NULL;
    if (head2 == NULL)
      head2 = current2 = temp2;
    else
    {
      current2->link = temp2;
      current2 = temp2;
    }
    current2->link = head2;
  }
  return count2;
}

void print_list1()
{

  list1 *temp1;
  if (head1 == NULL)
    printf("\nempty list");
  temp1 = head1;
  printf("%d", temp1->data);
  temp1 = temp1->link;
  while (temp1 != current1->link)
  {
    printf("%d", temp1->data);
    temp1 = temp1->link;
  }
  printf("\n");
}
void print_list2()
{
  list2 *temp2;
  if (head2 == NULL)
    printf("\nempty list");
  temp2 = head2;
  printf("%d", temp2->data);
  temp2 = temp2->link;
  while (temp2 != head2)
  {
    printf("%d", temp2->data);
    temp2 = temp2->link;
  }
  printf("\n");
}

void Add(int c1, int c2)
{
  int carry = 0, s, i;
  list1 *t1;
  list2 *t2;
  sum *t;

  t1 = head1;
  t2 = head2;
  i = c1 > c2 ? c1 : c2;
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
  t->link = NULL;
  t1 = t1->link;
  t2 = t2->link;
  if (head == NULL)
    head = current = t;
  else
  {
    current->link = t;
    current = t;
  }
  current->link = head;
  while (i--)
  {
    if (t1 == head1)
    {
      t1->data = 0;
    }

    if (t2 == head2)
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
    t->link = NULL;
    if (t1 != head1)
      t1 = t1->link;
    if (t2 != head2)
      t2 = t2->link;

    current->link = t;
    current = t;

    current->link = head;
  }
}
void printSum()
{
  sum *temp;
  if (head == NULL)
    printf("empty list");
  temp = head;
  printf("%d", temp->data);
  temp = temp->link;
  while (temp != head)
  {
    printf("%d", temp->data);
    temp = temp->link;
  }
  printf("\n");
}

void reverse_list1()
{
   struct list1 *pre,*t,*ahead;
  pre=t=head1;
  ahead=head1->link;
  t->link=current1;
  t=ahead;
  while(pre!=current1){
    ahead=ahead->link;
    t->link=pre;
    pre=t;
    t=ahead;
  }
  current1=head1;
  head1=pre;
}
void reverse_sum()
{
  struct sum *pre,*t,*ahead;
  pre=t=head;
  ahead=head->link;
  t->link=current;
  t=ahead;
  while(pre!=current){
    ahead=ahead->link;
    t->link=pre;
    pre=t;
    t=ahead;
  }
  current=head;
  head=pre;
}
