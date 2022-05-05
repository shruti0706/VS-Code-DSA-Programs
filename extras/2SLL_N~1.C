//creating single linked list of n node using DMA

#include<stdio.h>
#include<stdlib.h>

struct employee {
	int eid;
	char name[30];
	struct employee *next;
}*start=NULL,*current=NULL;
static int count=1;
int entry();
void view();
int modify();
int search();
int delete();
int main()
{
	int ch ;
	//clrscr();
	while (1)
	{

		printf("\n\n1.enter record\n2.view record\n3.Modify record\n4.Search Record\n5.Delete record\n6.Exit\n\nEnter choice :");
		scanf("%d", &ch);

		if (ch == 1)
			entry();
		else if (ch == 2)
			view();
		else if (ch == 3)
			modify();
	       	else if (ch == 4)
		   	search();
		else if (ch == 5)
			delete();
		else if (ch == 6)
			exit(0);
		else
			printf("Please enter a valid choice.");
	}
	//getch();
	return 0;
}
int entry(){
	struct employee *temp;
	temp=(struct employee *)malloc(sizeof(struct employee));
	printf("Enter employee id for employee %d:",count);
	scanf("%d",&temp->eid);
	printf("Enter name of employee %d:",count);
	scanf("%s",&temp->name);
	temp->next=NULL;
	if(start==NULL)
		start=current=temp;
	
else
	current->next=temp;

current=temp;
 
	count++;
	return 1;
       }
       
void view(){
	struct employee *temp;
	temp=start;
		if(start==NULL){
		printf("No record found");
		return;
	}
	printf("\n%9s%9s","Employee ID","Employee name");
	while (temp!=NULL){
    printf("\n%9d%9s",temp->eid,temp->name);
    temp=temp->next;
	}
	//printf("\n%9d%9s",temp->eid,temp->name);

}
int modify(){
struct employee *temp;
	int id,f=0;
		if(start==NULL){
		printf("No record found");
		return;
	}
	printf("\nEnter employee id whose record is to be modified :");
	scanf("%d", &id);

	temp=start;
	while(temp!=NULL){
		if(temp->eid==id){
			printf("enter employee name for employee id %d",id);
			scanf("%s",&temp->name);
			f=1;
			break;
		}
		temp=temp->next;
	}
if(f)
	printf("record modified successfully");
else
	printf("enter valid employee id");

return 1;


}
int search(){
struct employee *temp;
	int id;
	if(start==NULL){
		printf("No record found");
		return;
	}
printf("\nEnter employee id whose record you want to search:");
	scanf("%d", &id);
printf("\n%9s%9s","Employee ID","Employee name");
temp=start;
	while(temp!=NULL){
		if(temp->eid==id){
			   printf("\n%9d%9s",temp->eid,temp->name);			
			break;
		}
		temp=temp->next;
	}
	return 1;
}

int delete(){
	struct employee *temp,*p;
	int id;
		if(start==NULL){
		printf("No record found");
		return;
	}
	printf("\nEnter employee id whose record you want to delete:");
	scanf("%d", &id);

	temp=start;
	if(temp->eid=id){
		start=start->next;
		free(temp);
	}
	else{
while(temp->eid!=id){
	p=temp;
	temp=temp->next;
}
	p->next=temp->next;
	free(temp);
}
	return 0;
}