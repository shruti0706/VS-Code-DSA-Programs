//double linked list with all operations
#include <stdio.h>
#include <stdlib.h>

//creating structure of linked list
struct list
{
    struct list *prev;
    int data;
    struct list *next;
} ;

//declaring functions
int create_node();
int count_node(struct list *head);
struct list *  add_data(int choic, struct list *temp,struct list *head);
struct list * link_NodeatEnd(struct list *temp,struct list *head);
struct list * link_NodeatStart(struct list *temp,struct list *head);
struct list * link_NodeatAnyposition(struct list *temp,struct list *head);
void print_list(struct list *head);
// void update_data(struct list *head);
void search_data(struct list *head);
struct list * delete_data(struct list *head);
struct list * reverse_list(struct list *head);

//to count the position of nodes
//static int count = 0;
//iski jgh count k liye ek alg function bnana kyuki ye throughout the program memory m space lega..aur func ko jb call krenge tb count bta kr fir memory free kr dega..
int main()
{   struct list *ptr,*head;
    struct list *temp, *t1;
    int choice, ch;

     clrscr();
head=NULL;
    while (1)
    {
        printf("\n1.Add data\n2.Show data\n3.Update list\n4.Search data\n5.Delete data\n6.Reverse list\n7.Exit\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
	    t1 = create_node();
	    temp = add_data(choice, t1,head);
            printf("\n1.At beginning\n2.At end\n3.At any position\nEnter the position where you want to add given data -");
            scanf("%d", &ch);
            switch (ch) //for linking the new node
            {
            case 1:
              head=  link_NodeatStart(temp,head);
                break;
            case 2:
                head=link_NodeatEnd(temp,head);
                break;
            case 3:
                head=link_NodeatAnyposition(temp,head);
                break;
	    default:
		printf("Enter valid choice");
	    }
	    break;
	case 2:
	    print_list(head);
	    break;
	case 3:
	    add_data(choice,0,head);
	    // update_data();
	    break;
	case 4:
	    search_data(head);
	    break;
	case 5:
	   head= delete_data(head);
        print_list(head);
	    break;
	case 6:
	    head= reverse_list(head);
        print_list(head);
	    break;
	case 7:
	    exit(0);
	    break;
	default:
	    printf("Enter valid choice");
	    break;
	}
    }
     getch();
    return 0;
}
int create_node()//allocates memory to new node and give its address to adddata()
{
    struct list *temp;
    temp = (struct list *)malloc(sizeof(struct list));
    return temp;
}
struct list *  add_data(int choic, struct list *temp, struct list *head)
{
    int position, i = 1;
    int count = count_node(head);

    if (choic == 1)
    {
	// struct list *temp;
	// temp = create_node();
	temp->next = NULL;
    temp->prev=NULL;
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
	temp = head;
	while (i != position)
	{
	    temp = temp->next;
	    i++;
	}
    }
    
      printf("\nEnter data -");
    scanf("%d", &temp->data);
    if(position==1)
    head->data=temp->data;
    
      return temp;
}
struct list * link_NodeatStart(struct list *temp,struct list *head)
{
    if (head != NULL)
    {
	temp->next = head;
	head->prev=temp;
    }
    head = temp;
    return head;
}
struct list * link_NodeatEnd(struct list *temp,struct list *head)
{struct list *current;
    if (head == NULL)
    {
	head = temp;
    }
    else
    {
        current=head;
        while(current->next!=NULL)
        current=current->next;
	current->next = temp;
	temp->prev=current;
    
    }
    return head;
}
struct list * link_NodeatAnyposition(struct list *temp,struct list *head)
{
    struct list *current;
    int position, count, i;

    count = count_node(head);
    printf("\nEnter the position where you want to insert data : ");
    scanf("%d", &position);
    if (position == 1)
head =link_NodeatStart(temp,head);
    else if (position == count + 1)
head=link_NodeatEnd(temp,head);
    else if (position > count + 1)
    {
	printf("\nEnter valid position");
	return;
    }
    else
    {
	current = head;
	for (i = 1; i < position - 1; i++)
	{
	    current = current->next;
	}
	temp->next = current->next;
    temp->prev=current;
	current->next = temp;
    current=temp->next;
    current->prev=temp;
    
    }
   return head;
}

void print_list(struct list *head)
{
    struct list *temp;
    temp = head;
     printf("\nhead is  %d",head->data);
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
// void update_data()
// {
//     struct list *temp;
//     int position, i = 1;
//     int count = count_node();
//     printf("Enter the position of data you want to update");
//     scanf("%d", &position);
//     if (position > count)
//     {
// 	printf("enter valid position");
// 	return;
//     }
//     temp = head;
//     while (i != position)
//     {
// 	temp = temp->next;
// 	i++;
//     }
//     printf("Enter new data for node %d-", i);
//     scanf("%d", &temp->data);
//     printf("data modified successfully");
// }
void search_data(struct list * head)
{
    struct list *temp;
    int position, i = 1;
    int count = count_node(head);
    printf("Enter the position of data you want to search");
    scanf("%d", &position);
    if (position > count)
    {
	printf("enter valid position");
	return;
    }
    temp = head;
    while (i != position)
    {
	temp = temp->next;
	i++;
    }
    printf("\nThe value at position %d id %d.", i, temp->data);
}
struct list * delete_data(struct list *head)
{
    struct list *temp, *cur;
    int position, i = 1;
    int count = count_node(head);
    printf("Enter the position of data you want to delete");
    scanf("%d", &position);
    if (position > count)
    {
	printf("enter valid position");
	return;
    }
    if (position==1){
        head=head->next;
	head->prev=NULL;
        }
        
        else{
    cur = temp = head;
    while (i != position)
    {
	cur = temp;
	temp = temp->next;
	i++;
    }

    cur->next = cur->next->next;
    temp->next->prev=cur;

    free(temp);
    cur=cur->next;
    }
    
    printf("\nData deleted successfully");
    return head;
}
struct list * reverse_list(struct list 
*head){
//  head=head->next;
// if(head->next!=NULL){
// reverse_list(head);
// }
// printf(" %d ->",head->data);
/*
struct list *head,*temp=head->next;
head=head;
current=head;
current->next=NULL;
current=temp;
while(temp!=NULL){
    temp=temp->next;
    current->next=head;
    head=current;
    current=temp;
}
head=head;
*/
struct list *temp,*ptr,*ahead;
temp=head;
ahead=head;
if(head->next==NULL)
return head;

while(ahead->next!=NULL){
    ahead=ahead->next;
 ptr=temp->next;
 temp->next=temp->prev;
 temp->prev=ptr;   
 temp=ahead;
}
ahead->next=ahead->prev;
ahead->prev=NULL;
head=ahead;

return head;
}

