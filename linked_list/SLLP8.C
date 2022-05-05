// Add a number to a single linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// structure for first list
typedef struct list1
{
  int data;
  struct list1 *link;
} list1;
list1 *head1, *current1;
//structure for number to be added in list
typedef struct list2
{
  int data;
  struct list2 *link;
} list2;
list2 *head2, *current2;
//structure for storing sum
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
  int count1,count2 ;
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
  }
  return count2;
}

void print_list1()
{

  list1 *temp1;
  if (head1 == NULL)
    printf("\nempty list");
  temp1 = head1;
  while (temp1 != NULL)
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
  while (temp2 != NULL)
  {
    printf("%d", temp2->data);
    temp2 = temp2->link;
  }
  printf("\n");
}

void Add(int c1, int c2)
{
  int carry = 0, s,i;
  list1 *t1;
  list2 *t2;
  sum *t;

  t1 = head1;
  t2 = head2;
i=c1>c2?c1:c2;
  while (i--)
  {
    if(t1==NULL){
      t1->data=0;
    }

    if(t2==NULL){
      t2->data=0;
    }
    t = (sum *)malloc(sizeof(sum));
    s = t1->data + t2->data+carry;
    if ((s / 10 )!= 0)
    {
      s=s%10;
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    t->data=s;
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
  }
}
void printSum()
{
  sum *temp;
  if (head == NULL)
    printf("empty list");
  temp = head;
  while (temp != NULL)
  {
    printf("%d", temp->data);
    temp = temp->link;
  }
  printf("\n");
}

void reverse_list1()
{
  struct list1 *head,*temp=head1->link;
head=head1;
current1=head;
current1->link=NULL;
current1=temp;
while(temp!=NULL){
    temp=temp->link;
    current1->link=head;
    head=current1;
    current1=temp;
}
head1=head;
}
void reverse_sum()
{
  struct sum *h,*temp=head->link;
h=head;
current=h;
current->link=NULL;
current=temp;
while(temp!=NULL){
    temp=temp->link;
    current->link=h;
    h=current;
    current=temp;
}
head=h;
}