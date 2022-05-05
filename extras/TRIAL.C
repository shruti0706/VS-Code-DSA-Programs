#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

struct loginCredential
{
   int userid;
    char password[50];
    
}l ;

struct Inventory
{
    int sno;
    int code;
    char name[50];
    int rate;
    int quantity;
    char gender;
    
}t;

void welcomepage();
void mainMenu(int i);
int loginpage();
int addProduct();
void editProduct();
void displayAllProducts(int i);
int searchEntry();
void deleteProduct();

int calculateBill();
static int sum = 0;
static int count = 0;
static int usercount = 0;

int main()
{
    clrscr();

     welcomepage();
    loginpage();

    getch();
    return 0;
}
void welcomepage()
{


    printf("*****");

    printf("\n\n\n\n\n\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t::\t\t\t\t\t\t\t\t\t::");

       printf("\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\tFASHION HUB\t\t\t\t::  \n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t A style for every story...     ::\n\t");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\n\n\n\n\n\n");
    printf("*****");


return;

}

int loginpage()
{
    
    struct loginCredential *pr;
    int ch, tempid;
    FILE *fptr;
    int choice;
    char AdminID[15];
    char upassword[12];
    printf("\nEnter 1 for AdminID:\n");
    printf("\nEnter 2 for UserID:\n");
    printf("\nEnter choice ");
    scanf("%d", &choice);

    if (choice == 1) // login for admin
    {

    printf("\nEnter AdminID:\n");
    scanf("%s", AdminID);

    printf("\nEnter password:\n");
    scanf("%s", upassword);

    if (strcmp(AdminID, "arun") == 0)
    {
        if (strcmp(upassword, "123") == 0)
        {

        printf("\nWelcome. LOGIN SUCCESS!");
        mainMenu(choice);
        }

        else
        {
        printf("\nWrong Password please try again");
        loginpage();
        }
    }
    else
    {
        printf("\nAdminID doesn't exist");
        loginpage();
    }
    }

    if (choice == 2) //login for user
    {

    printf("\nEnter 1 for New User\n");
    printf("\nEnter 2 for Existing User\n");
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        pr = (struct loginCredential *)malloc(sizeof(struct loginCredential));
        printf("\nenter new user id ");
        scanf("%d", &pr->userid);

        printf("\nenter password");
        scanf("%s", pr->password);
        //fflush(stdin);

     fptr = fopen ("userrecord.txt", "a");
     if (fptr == NULL)
    {
    fprintf(stderr, "\nError opening file\n");
    exit (1);
    }
  fwrite(&pr,sizeof(pr),1,fptr);
    fclose(fptr);
        usercount++;
        printf("\nlogin successful,new user added....");
        mainMenu(choice);
    }
    else if (ch == 2)
    {
        printf("\nEnter userid");
        scanf("%d", &tempid);
        printf("\nEnter password");
        scanf("%s", upassword);
        
    }
    else
    {
        printf("\nenter valid choice");
        loginpage();
    }
    }
    return 1;

}

void mainMenu(int i)
{

  int choice;
  while (1)
 {
    if (i == 1)
    {
      printf("\n\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
      printf("\n\t\t\t+   CLOTHING STORE MANAGEMENT SYSTEM   +      ");
      printf("\n\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");

      printf("\n\t\t\t\t MAIN MENU\n\t\t\t\t\t\t");
      printf("\n\t\t [1] ADD PRODUCT\t\t\t\t");
      printf("\n\t\t [2] EDIT PRODUCT\t\t\t\t");
      printf("\n\t\t [3] SEARCH PRODUCT\t\t\t\t");
      printf("\n\t\t [4] DISPLAY PRODUCT\t\t\t\t");
      printf("\n\t\t [5] DELETE PRODUCT\t\t\t\t");
      printf("\n\t\t [6] EXIT\t\t\t\t\t");
      printf("\n\t\tENTER CHOICE\n\n");

      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
    addProduct();
    break;
      case 2:
    editProduct();
    break;
      case 3:
    searchEntry();
    break;
      case 4:
    displayAllProducts(i);
    break;
      case 5:
    deleteProduct();
    break;
      case 6:
    exit(0);
      }
    }
  }
  if (i == 2)
  {
    printf("\n\t\t\t\t\t MAIN MENU \n");
    printf("\n\t\t\t| [1] DISPLAY PRODUCT\t\t\t\t|");
    printf("\n\t\t\t\t| [2] SEARCH ANY PRODUCT\t\t\t\t|");
    printf("\n\t\t\t| [3] MAKE PURCHASE\t\t\t\t|");
    printf("\n\t\t\t| [4] EXIT\t\t\t\t");
    printf("\n\t\t\t|ENTER CHOICE\n\n");

    scanf("%d", &choice);
    if (choice == 1)
    {
      displayAllProducts(i);
    }
    else if (choice == 2)
      searchEntry();
    else if (choice == 3)
    {
      calculateBill();
      printf("total amount =%d", sum);
    }
    else if (choice == 4)
      exit(0);
    else
    {
      printf("enter valid choice");
    }
  }

}
int addProduct()
{
    FILE *ptr=NULL;
    char ch;
    int j;

    
    printf("\nEnter Product code:");
    scanf("%d", &t.code);
    fflush(stdin);
    printf("\nEnter new Product name :");
    scanf("%s", t.name);
    t.sno = count + 1;
    fflush(stdin);
    printf("\nEnter new product rate :");
    scanf("%d", &t.rate);
    fflush(stdin);
    printf("\nEnter new product quantity :");
    scanf("%d", &t.quantity);
    
    printf("\nEnter the gender :");
    scanf("%c", t.gender);
    fflush(stdin);
    ptr = fopen ("record.txt", "a");
     if (ptr == NULL)
    {
    fprintf(stderr, "\nError opening file\n");
    exit (1);
    }
    fwrite(&t,sizeof(t),1,ptr);
    fclose(ptr);

    count++;
    printf("record added successfully");
    return ;
}
void displayAllProducts(int i)
{int a,j,choice;
    FILE *ptr;
   
    ptr=fopen("record.txt","r");
     if(ptr==NULL)
    {
        printf("can't read file");
        mainMenu(choice);
    getch();
        //exit(1);
    }
       printf("\n%9s %9s %9s %9s %9s %9s", "sno", " code ", " name ", " rate  ", " quantity "," gender ");
    while(fread(&t,sizeof(t),1,ptr)==1)
        {
           printf("\n%9d %9d %9s %9d %9d %9c ", t.sno, t.code, t.name, t.rate, t.quantity,t.gender);
        }
    fclose(ptr);
}
int searchEntry()
{
    
    int found,scd,fp,ptr ,code,ch,flag=0;
    // FILE *fp;
     fp=fopen("record.txt","r");
     if (fp==NULL)
     {
         printf("cannot open the file ");
         return;
     }
         
           printf("\nEnter product code you want to search  : ");
           fflush(stdin);
           scanf("%d",&scd);

     while(fread(&t,sizeof(t),1,ptr)>0 && flag==0)
            {
         if (t.code==scd)
         {
             flag=1;
             printf("\n all  details from given product code %d : ",scd);
                   printf("\n:: name \t rate \t quantity ");
                     printf("\n%9s %9d %9d  ", t.name, t.rate, t.quantity);
                           printf("\n________");
         
          fseek(fp,-(long)sizeof(t),1);
          fwrite(&t,sizeof(t),1,fp);
     
         //             printf("\nrecordd updatedddddddddd  ");
               }

            
                if(flag==0)
                {
                        printf("\nsomething went wrong ");
                }
     fclose(fp);
            }
             
        

          
        while(ch==1);

       return 0;

if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);
    
    
    
    
    
    
    
    
    
    
    // FILE *ptr;
    // //  struct Inventory *temp;
    // int cd,f=0;

    // printf("\nEnter Product code you want to search : ");
    // scanf("%d",&t.code);
    // ptr = fopen("record.txt","r");
    // if(ptr==NULL)
    // {
    //     printf("Couldn't find the product. Try again");
    //     return;
    
    
    

 
          // return 0;
}
void deleteProduct()    //delete products
{
    
     int cd;
    FILE *fp1, *fp2;
    printf("\nEnter product code you want to delete :");
    scanf("%d", &cd);
    fp1 = fopen("record.txt", "r+");
    fp2 = fopen("newrecord.txt", "a+");
    // rewind(fp1);
    //  rewind(fp2);
    if (fp1 == NULL)
    {
        printf("error opening file");
        exit(0);
    }
    while (fread(&t, sizeof(struct Inventory), 1, fp1))
    {

        if (t.code != cd)
        {
            fwrite(&t, sizeof(struct Inventory), 1, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    remove("record.txt");
    rename("newrecord.txt", "record.txt");
    printf("record deleted successfully");
    return 0;
}
    
    
    
    
    
    
    
    // struct Inventory *temp, *p;
    // int cd;
  
    // printf("\nEnter product code you want to delete :");
    // scanf("%d", &cd);

    //     printf("record deleted successfully");
   

void editProduct() //edit products
{
    
     int found,pcd,fp,ptr ,code,ch,flag=0;
    // FILE *fp;
     fp=fopen("record.txt","r");
     if (fp==NULL)
     {
         printf("cannot open the file ");
         return;
     }
         {
           printf("\n::enter product code  to edit: ");
           fflush(stdin);
           scanf("%d",&pcd);

     while(fread(&t,sizeof(t),1,ptr)>0 && flag==0)
            {
         if (t.code==pcd){
             flag=1;
             printf("\n old entry from record : ");
                   printf("\n:: name \t rate \t quantity ");
                     printf("\n%9s %9d %9d  ", t.name, t.rate, t.quantity);
                    
                     printf("\nEnter updated Product name");
    scanf("%s", t.name);
//    t.sno = count + 1;
    fflush(stdin);
    printf("\nEnter updated product rate");
    scanf("%d", &t.rate);
    fflush(stdin);
    printf("\nEnter updated product quantity");
    scanf("%d", &t.quantity);
    fflush(stdin);
	  fseek(fp,-(long)sizeof(t),1);
	  fwrite(&t,sizeof(t),1,fp);
          
                       printf("\nrecordd updatedddddddddd  ");
                    }

                }
                if(flag==0)
                {
                        printf("\nsomething went wrong ");
                }
     fclose(fp);
            }
             
        

          
        while(ch==1);

       return 0;

if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

	    fclose(fp);
    
    
    
    
    
    
    
    
    
    
    
    
    
    // struct Inventory *temp;
    // int cd, f = 0;
  
    // printf("\nEnter product code you want to edit :");
    // scanf("%d", &cd);

    
    // while (temp != NULL)
    // {
    //     if (temp->code == cd)
    //     {
    //         printf("\nenter product name for product code %d", cd);
    //         scanf("%s", &temp->name);
    //          temp->sno = count + 1;
    // fflush(stdin);
    // printf("\nEnter new product rate");
    // scanf("%d", &temp->rate);
    // fflush(stdin);
    // printf("\nEnter new product quantity");
    // scanf("%d", &temp->quantity);
    // fflush(stdin);
    // printf("\nEnter the gender ");
    // scanf("%s", temp->gender);
    // fflush(stdin);
    //         f = 1;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // if (f)
    //     printf("\nrecord edited successfully");
    // else
    //     printf("\nenter valid product code ");

   // return 1;
}
int calculateBill()
{
    struct Inventory *temp;
    static int try = 1;
    int id = 1, i, f = 0, qty, total;
  
    printf("\nenter 0 to stop taking inputs");

    while (id != 0)
    {
        printf("\nEnter Product code - ");
        scanf("%d", &id);
        
        // while (temp != NULL)
        // {

        //     if (temp->code == id)
        //     {
        //         f = 1;
        //         printf("\nEnter quantity ");
        //         scanf("%d", &qty);
        //         if (qty < temp->quantity)
        //         {

        //             temp->quantity = temp->quantity - qty;
        //         }
        //         else
        //         {
        //             printf("\ninsufficient quantity.try again");
        //             break;
        //         }

        //         break;
        //     }
        //     temp = temp->next;
        // }
        // if (f == 0)
        //     printf("\nid not found");
        // if (try == 1)
        // {
        //     printf("\n%9s %9s %9s %9s %9s %9s", "sno", " code ", " name ", " rate  ", " quantity ", " total ");
        //     ++try;
        // }
        // total = temp->rate * temp->quantity;
        // printf("\n%9d %9d %9s %9d %9d ", temp->sno, temp->code, temp->name, temp->rate, temp->quantity, total);
        // sum = sum + total;
    }
}