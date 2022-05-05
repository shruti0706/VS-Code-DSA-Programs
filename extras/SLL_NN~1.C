//creating single linked list of n node using DMA

#include<stdio.h>
#include<stdlib.h>

struct employee {
	int eid;
	char name[30];
	struct employee *next;
}*start=NULL,*current=NULL,*temp;
static int count=1;
void entry();
void view();

int main()
{
	int ch ;
	clrscr();
	while (1)
	{

		printf("\n\n1.enter record\n2.view record\n3.Exit\n\nEnter choice :");
		scanf("%d", &ch);

		if (ch == 1)
			entry();
		else if (ch == 2)
			view();
		else if (ch == 3)
			exit(0);
		else
			printf("Please enter a valid choice.");
	}
	getch();
	return 0;
}
void entry(){

	clrscr();
	if(count==1){
		start=(struct employee *)malloc(sizeof(struct employee));
		printf("Enter employee id for employee %d:",count);
		scanf("%d",&start->eid);
		printf("Enter name of employee %d:",count);
		scanf("%s",&start->name);
		start->next=NULL;
		temp=start;
	}
		else{
		current=(struct employee *)malloc(sizeof(struct employee));
		printf("Enter employee id for employee %d:",count);
		scanf("%d",&current->eid);
		printf("Enter name of employee %d:",count);
		scanf("%s",&current->name);
		current->next=NULL;
		temp->next=current;
		temp=temp->next;
	}
count++;
}

void view(){
	temp=start;
	printf("\n%9s%9s","Employee ID","Employee name");
	while (temp->next!=NULL){
    printf("\n%9d%9s",temp->eid,temp->name);
    temp=temp->next;
	}
	printf("\n%9d%9s",temp->eid,temp->name);



}