//detect and remove loop in a single linked list
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
} *start = NULL, *current = NULL;
int create_node();
int count_node();
int add_data();
int detectCycleAndRemove();
void link_NodeatEnd(struct list *temp);
void print_list();
void formloop(){
    struct list *ptr;
    int i,postn;
    printf("enter position where you want to link last node");
    scanf("%d",&postn);
            ptr = start;
         
            for (i = 1; i < postn; i++)
            {
                ptr = ptr->next;
            }
            current->next = ptr;
            printf("loop created");
}
int main()
{
    int choice;
   clrscr();
while (1){
     printf("\n1.Add data\n2.print list\n3.Detect and Remove loop\n4.Exit\n5.link to make a loop\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_data();
        break;
    case 2:
        print_list();
        break;
    case 3:
    detectCycleAndRemove();
        break;
    case 4:
        exit(0);
        break;
    case 5:
        formloop();
        break;
    default:
        printf("enter valid choice");
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
int add_data()
{
    struct list *temp;
    int position, i = 1;
    temp = create_node();
   
  
   
    temp->next = NULL;
    printf("\nEnter data -");
    scanf("%d", &temp->data);
    //    return temp;
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
        current->next = temp;
        current = temp;
    }
}
int count_node()
{
    int count = 0;
    struct list *temp;
    temp = start;

    while (temp != current)
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
    // printf("%d",count_node());
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
        current = temp;
    }
}
int detectCycleAndRemove(){
    struct list *slowptr,*fastptr;
    int i=0,flag=0;
    slowptr=fastptr=start;

    while(i<20){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr)
        {
            flag=1;
            break;
        }
        i++;
    }
    if(flag){
        printf("\nLoop Detected at postn %d\n",i);
        fastptr=start;
        while(slowptr->next!=fastptr->next){
            slowptr=slowptr->next;
            fastptr=fastptr->next;
        }
        slowptr->next=NULL;
        printf("Loop removed");
    }



}