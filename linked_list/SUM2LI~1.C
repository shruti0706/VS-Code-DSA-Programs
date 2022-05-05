//sum of polynomials via linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// structure for first polynomial 
typedef struct list1
{
  int data;
  struct list1 *link;
} list1;
list1 *head1, *current1;
//structure for second polynomial 
typedef struct list2
{
  int data;
  struct list2 *link;
} list2;
list2 *head2, *current2;
//structure for storing sum of polynomial 
typedef struct sum
{
  int data;
  struct sum *link;
} sum;
sum *head,*current;

//declaring functions
int add_data_list1(int degree);
int add_data_list2(int degree);
void print_list1(int degree);
void print_list2(int degree);
void sumOfPolynomial();
void printSum(int degree);
int main()
{
  int degree, i;
clrscr();
  printf("Enter degree of polynomials: ");
  scanf("%d", &degree);

  add_data_list1(degree);
  add_data_list2(degree);
  printf("\nThe polynomials are \n");
  print_list1(degree);

  print_list2(degree);
 sumOfPolynomial();
 printSum(degree);
getch();
  return 0;
}
int add_data_list1(int degree)
{
  list1 *temp1;
  int i, n;
  printf("Enter data for first polynomial : \n");
  n = degree;
  for (i = 0; i <= degree; i++, n--)
  {
    temp1 = (list1 *)malloc(sizeof(list1));
    printf("Enter coefficient of x^%d ", n);
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
  return 1;
}

int add_data_list2(int degree)
{
  list2 *temp2;
  int i, n;
  printf("Enter data for second polynomial : \n");
  n = degree;
  for (i = 0; i <= degree; i++, n--)
  {
    temp2 = (list2 *)malloc(sizeof(list2));
    printf("Enter coefficient of x^%d ", n);
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
  return 1;
}

void print_list1(int degree)
{
  int n;
  list1 *temp1;
  n=degree;
  temp1 = head1;
  while (temp1 != NULL)
  {if(n!=0)
    printf("%d x^%d + ", temp1->data,n);
    else
    printf("%d", temp1->data,n);
    n--;
    temp1 = temp1->link;
  }
  printf("\n");
}

void print_list2(int degree)
{int n;
  list2 *temp2;
   n=degree;
  temp2 = head2;
  while (temp2 != NULL)
  {if(n!=0)
    printf("%d x^%d + ", temp2->data,n);
      else
    printf("%d", temp2->data,n);
    n--;
    temp2 = temp2->link;
  }
printf("\n");
}

void sumOfPolynomial(){
list1 *t1;
list2 *t2;
sum *t;
if(head1==NULL||head2==NULL){
printf("\nempty polynomial..add atleast one value");
return ;
}
t1=head1;
t2=head2;
while(t1!=NULL){
  t=(sum *)malloc(sizeof(sum));
t->data = t1->data + t2->data;
t->link=NULL;
t1=t1->link;
t2=t2->link;
if(head==NULL)
head=current=t;
else{
current->link=t;
current=t;
}
}
}
void printSum(int degree){
  sum *t;
  int n=degree;
  t=head;
  printf("\n\nSum of polynomials are : ");
  while(t!=NULL){
    if(n!=0)
    printf("%d x^%d + ",t->data,n);
 else
     printf("%d ",t->data,n);
    n--;
    t=t->link;
  }
}