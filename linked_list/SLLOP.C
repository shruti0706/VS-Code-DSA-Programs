//single linked list with all operations
#include <stdio.h>
#include <stdlib.h>

//creating structure of linked list
struct list
{
    int data;
    struct list *next;
} *start = NULL, *current = NULL;

//declaring functions
int create_node();
int count_node();
int add_data(int choic, struct list *temp);
void link_NodeatEnd(struct list *temp);
void link_NodeatStart(struct list *temp);
void link_NodeatAnyposition(struct list *temp);
void print_list();
void update_data();
void search_data();
void delete_data();
void reverse_list();
// struct list * reverseByRecrsn(struct list *temp){
//      temp=temp->next;
// if(temp->next!=NULL){   
// reverseByRecrsn(temp);
// }



// }
//to count the position of nodes
//static int count = 0;
//iski jgh count k liye ek alg function bnana kyuki ye throughout the program memory m space lega..aur func ko jb call krenge tb count bta kr fir memory free kr dega..
int main()
{   struct list *ptr;
    struct list *temp, *t1;
    int choice, ch;
    // clrscr();

    while (1)
    {
        printf("\n1.Add data\n2.Show data\n3.Update list\n4.Search data\n5.Delete data\n6.Reverse list\n7.Exit\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t1 = create_node();
            temp = add_data(choice, t1);
            printf("\n1.At beginning\n2.At end\n3.At any position\nEnter the position where you want to add given data -");
            scanf("%d", &ch);
            switch (ch) //for linking the new node
            {
            case 1:
                link_NodeatStart(temp);
                break;6
            case 2:
                link_NodeatEnd(temp);
                break;
            case 3:
                link_NodeatAnyposition(temp);
                break;
	    default:
		printf("Enter valid choice");
	    }
	    break;
	case 2:
	    print_list();
	    break;
	case 3:
	    add_data(choice,0 );
	    // update_data();
	    break;
	case 4:
	    search_data();
	    break;
	case 5:
	    delete_data();
	    break;
	case 6:
	     reverse_list();
        // ptr->data=start->data;
      // reverseByRecrsn(start);
        print_list();
	   // printf(" %d",start->data);
	    break;
	case 7:
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
	temp->next = NULL;

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
	// printf("Enter new data for node %d-", i);
	// scanf("%d", &temp->data);
       // printf("data modified successfully");
    }
      printf("\nEnter data -");
    scanf("%d", &temp->data);
      return temp;
}
void link_NodeatStart(struct list *temp)
{
    if (start == NULL)
    {
	start = current = temp;
    }
    else
    {
	temp->next = start;
	start = temp;
    }
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
void link_NodeatAnyposition(struct list *temp)
{
    struct list *previous;
    int position, count, i;

    count = count_node();
    printf("\nEnter the position where you want to insert data : ");
    scanf("%d", &position);
    if (position == 1)
	link_NodeatStart(temp);
    else if (position == count + 1)
	link_NodeatEnd(temp);
    else if (position > count + 1)
    {
	printf("\nEnter valid position");
	return;
    }
    else
    {
	previous = start;
	for (i = 1; i < position - 1; i++)
	{
	    previous = previous->next;
	}
	temp->next = previous->next;
	previous->next = temp;
    }
}
int count_node()
{
    int count = 0;
    struct list *temp;
    temp = start;

    while (temp != NULL)
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
        current=temp;
    }
}
void update_data()
{
    struct list *temp;
    int position, i = 1;
    int count = count_node();
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
    printf("Enter new data for node %d-", i);
    scanf("%d", &temp->data);
    printf("data modified successfully");
}
void search_data()
{
    struct list *temp;
    int position, i = 1;
    int count = count_node();
    printf("Enter the position of data you want to search");
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
    printf("\nThe value at position %d id %d.", i, temp->data);
}
void delete_data()
{
    struct list *temp, *p;
    int position, i = 1;
    int count = count_node();
    printf("Enter the position of data you want to delete");
    scanf("%d", &position);
    if (position > count)
    {
	printf("enter valid position");
	return;
    }
    p = temp = start;

    while (i != position)
    {
	p = temp;
	temp = temp->next;
	i++;
    }

    p->next = temp->next;
    if (position == count)
	current = p;
    p = p->next;

    free(temp);
    if (position == 1)
	start = p;

    printf("\nData deleted successfully");
}
void reverse_list(){
//  head=head->next;
// if(head->next!=NULL){
   
// reverse_list(head);
// }
// printf(" %d ->",head->data);
struct list *head,*temp=start->next;
head=start;
current=head;
current->next=NULL;
current=temp;
while(temp!=NULL){
    temp=temp->next;
    current->next=head;
    head=current;
    current=temp;
}
start=head;

}

