// Sorted merge for 2 single linked lists
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
//structure for second list
typedef struct list2
{
  int data;
  struct list2 *link;
} list2;
list2 *head2, *current2;
//structure for storing merged list
typedef struct merge
{
  int data;
  struct merge *link;
} merge;
merge *head, *current;

//declaring functions
int add_data_list1();
int add_data_list2();
void print_list1();
void print_list2();
void Merge(int c1, int c2);
void printMergedlist();

int main()
{
  int count1, count2;
  clrscr();

  count1 = add_data_list1();
  print_list1();

  count2 = add_data_list2();
  print_list2();
  Merge(count1, count2);
  printMergedlist();
  getch();
  return 0;
}
int add_data_list1()
{
  list1 *temp1;
  int i, n;
  printf("\nEnter total number of elements : ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    temp1 = (list1 *)malloc(sizeof(list1));
    printf("\nEnter data %d in sorted order : ", i);
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
  int i, n;
  printf("\nEnter total number of elements : ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    temp2 = (list2 *)malloc(sizeof(list2));
    printf("\nEnter data %d in sorted order : ", i);
    scanf("%d", &temp2->data);
    temp2->link = NULL;
    if (head2 == NULL)
      head2 = current2 = temp2;
    else
    {
      current2->link = temp2;
      current2 = temp2;
    }
  }
  return n;
}
void print_list1()
{

  list1 *temp1;
  if (head1 == NULL)
    printf("\nempty list");
  temp1 = head1;
  while (temp1 != NULL)
  {
    printf("%d->", temp1->data);
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
    printf("%d->", temp2->data);
    temp2 = temp2->link;
  }
  printf("\n");
}

void Merge(int c1, int c2)
{
  int d;
  list1 *t1;
  list2 *t2;
  merge *t;
  t1 = head1;
  t2 = head2;
  while (t1 != NULL || t2 != NULL)
  {
    t = (merge *)malloc(sizeof(merge));
    if (t1->data == t2->data)
    {
      t->data = t1->data;
      t1 = t1->link;
      t2 = t2->link;
    }
    else if (t1 == NULL)
    {
      t->data = t2->data;
      t2 = t2->link;
    }
    else if (t2 == NULL)
    {
      t->data = t1->data;
      t1 = t1->link;
    }
    else
    {
      d = t1->data < t2->data ? 1 : 2;
      if (d == 1)
      {
        t->data = t1->data;
        t1 = t1->link;
      }
      if (d == 2)
      {
        t->data = t2->data;
        t2 = t2->link;
      }
    }
    t->link = NULL;

    if (head == NULL)
      head = current = t;
    else
    {
      current->link = t;
      current = t;
    }
  }
}

void printMergedlist()
{
  merge *temp;
  if (head == NULL)
    printf("empty list");
  temp = head;
  while (temp != NULL)
  {
    printf("%d->", temp->data);
    temp = temp->link;
  }
  printf("\n");
}
