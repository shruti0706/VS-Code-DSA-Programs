//employee details using struct pointer

#include <stdio.h>
#include <conio.h>
#define empsize 5
struct Employee
{
	int E_id;
	char f_name[20];
	char l_name[20];
	char email[20]; 
	char mobile[12];
} dollop[empsize],*ptr;
void entry();
void view();
void modify();
void search();
void delete();
static int a=0;
void main()
{

	int ch ;
	clrscr();
	ptr=&dollop;
	while (1)
	{

		printf("\n\n1.enter record\n2.view record\n3.modify record\n4.search record\n5.Delete record\n6.Exit\n\nEnter choice :");
		scanf("%d", &ch);

		if (ch == 1)
			entry(ptr++);
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
	getch();
}
void entry(struct Employee *qtr)
{
	// static int a=0;
	int  j;
	printf("\nEmployee id should not be repeated and cannot be zero.\n");
	
		printf("\nEnter employee id, first name,last name,email and mobile number respectively for employee %d", a+1);
		scanf("%d%s%s%s%s", qtr->E_id, qtr->f_name, qtr->l_name, qtr->email, qtr->mobile);
	
	
		for (j = 0; j < a; j++)
		{
			if (dollop[a].E_id == dollop[j].E_id)
			{
				printf("duplicate employee id..re enter");
				entry(ptr);
			}
			if (dollop[a].E_id == 0)
			{
				printf("Employee id cannot be zero..re enter");
				entry(ptr);
			}
		}
		++a;
	}

void view()
{
	int i;
	if (dollop[0].E_id == 0)
	{
		printf("No record found");
		return;
	}

	for (i = 0; i < a; i++)
	{	if (dollop[i].E_id == 0)
	{
		return;
	}
		printf("\nEmployee id : %d \nfirst name : %s \nlast name : %s \nemail : %s \nmobile number  : %s \n", dollop[i].E_id, dollop[i].f_name, dollop[i].l_name, dollop[i].email, dollop[i].mobile);
	}
}

void modify()
{
	int id, i,f;
	if (dollop[0].E_id == 0)
	{
		printf("No record found");
		return;
	}

	printf("\nEnter employee id whose record is to be modified :");
	scanf("%d", &id);
	for (i = 0; i < a; i++)
	{
		f=1;

		if (dollop[i].E_id == id)
		{
			printf("\nEnter first name,last name,email and mobile number respectively for employee having id  %d", id);
			scanf("%s%s%s%s", &dollop[i].f_name, &dollop[i].l_name, &dollop[i].email, &dollop[i].mobile);
			break;
		}
		else
		{
			f=0;
			}
}
if(f==0)
printf("\nid not found");
}

void search()
{
	int id, i,f;
	if (dollop[0].E_id == 0)
	{
		printf("No record found");
		return;
	}
	printf("\nEnter employee id whose record you want to search:");
	scanf("%d", &id);
	for (i = 0; i < a; i++)
	{f=1;

		if (dollop[i].E_id == id)
		{
			printf("\nEmployee id : %d \nfirst name : %s \nlast name : %s \nemail : %s \nmobile number  : %s \n", dollop[i].E_id, dollop[i].f_name, dollop[i].l_name, dollop[i].email, dollop[i].mobile);
		break;
		}

		else
		{
			f=0;
		}
	}
	if(f==0)
printf("\nid not found");
}

void delete(){
	int id, i,f,j;
	if (dollop[0].E_id == 0)
	{
		printf("No record found");
		return;
	}
	printf("\nEnter employee id whose record you want to delete:");
	scanf("%d", &id);

	for (i = 0; i < a; i++)
	{f=1;

		if (dollop[i].E_id == id)
		{ 
			for(j=i;j<a-1;j++){
			    dollop[j].E_id=dollop[j+1].E_id;
			   *dollop[j].f_name=*dollop[j+1].f_name;
			   *dollop[j].l_name=*dollop[j+1].l_name;
			   *dollop[j].email=*dollop[j+1].email;
			   *dollop[j].mobile=*dollop[j+1].mobile;

			}
			 dollop[j].E_id=0;
		   
			printf("record deleted successfully");
			return;

			}

		else
		{
			f=0;
		}
	}
	if(f==0)
printf("\nid not found");
}

