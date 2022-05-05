
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct loginCredential
{
    int userid;
    char password[50];

} l;

struct Inventory
{
    int sno;
    int code;
    char name[50];
    int rate;
    int quantity;
    char gender;
struct Inventory *next;
} t,*start=NULL,*current=NULL;

void welcomepage();
void mainMenu(int i);
int loginpage();
int addProduct();
void editProduct();
void displayAllProducts(int i);
void createlist();
int searchEntry();
int deleteProduct();
int calculateBill();
static int sum = 0;
static int count = 0;
static int usercount = 0;

int main()
{
    int k;
    clrscr();
   
    welcomepage();
    loginpage();
    getch();
    return 0;
}
void welcomepage()
{

    printf("***************************************");

    printf("\n\n\n\n\n\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t::\t\t\t\t\t\t\t\t\t::");

    printf("\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\tFASHION HUB\t\t\t\t::  \n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t\t\t\t\t::\n\t::\t\t\t\t\t A style for every story...     ::\n\t");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\n\n\n\n\n\n");
    printf("***************************************");

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
            createlist();
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
    FILE *ptr;
    char another = 'Y';
    clrscr();
    fseek(ptr, 0, SEEK_END);
    ptr = fopen("record.txt", "a");

    if (ptr == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    while (another == 'Y')
    {
        printf("\nEnter Product code:");
        scanf("%d", &t.code);
        printf("\nEnter new Product name");
        scanf("%s", t.name);
        fflush(stdin);
        t.sno = count + 1;
        printf("\nEnter new product rate");
        scanf("%d", &t.rate);

        printf("\nEnter new product quantity");
        scanf("%d", &t.quantity);
        printf("\nEnter the gender(m/f)");
        scanf(" %c", &t.gender);
        fwrite(&t, sizeof(t), 1, ptr);
        printf("\nwant to add another record? (Y/N) :");
        fflush(stdin);
        scanf(" %c", &another);
        if (another == 'N')
        {
            break;
        }
        count++;
    }

    fclose(ptr);
    printf("record added successfully");
    return 0;
}
void createlist(){
    struct Inventory *node;
    FILE *fp=open("record.txt","r");

    while(fscanf(fp,"%d,%s,%d,%d,%c,&t.code,t.name,&t.rate,&t.quantity,&t.gender")!=EOF){
        node=(struct Inventory *)malloc(sizeof(struct Inventory));
        node->code=t.code;
        strcpy(node->name,t.name);
        node->rate=t.rate;
        node->quantity=t.quantity;
        node->gender=t.gender;
        node->next=NULL;

        if(start==NULL)
            current=start=node;
        else
            current=current->next=node;
    }

fclose(fp);
return;
}
void displayAllProducts(int i)
{
    int a, j;
    FILE *ptr;
    clrscr();
    ptr = fopen("record.txt", "r");
    if (ptr == NULL)
    {
        printf("can't read file");
        //  getch();
        exit(1);
    }
    rewind(ptr);
    printf("\n%9s %9s %9s %9s %9s %9s", "sno", " code ", " name ", " rate  ", " quantity ", " gender ");
    while (fread(&t, sizeof(t), 1, ptr) == 1)
    {
        printf("\n%9d %9d %9s %9d %9d %9c ", t.sno, t.code, t.name, t.rate, t.quantity, t.gender);
    }
    fclose(ptr);
}
int searchEntry()
{

    struct Inventory *temp;
    int cd, f = 0;

    printf("\nEnter Product code you want to search : ");
    scanf("%d", &cd);

    return 0;
}
int deleteProduct() //delete products
{

    int cd;
    FILE *fp1, *fp2;
    printf("\nEnter product code you want to delete :");
    scanf("%d", &cd);
    fp1 = fopen("record.txt", "r+");
    fp2 = fopen("newrecord.txt", "a+");
    // rewind(fp1);
    //  rewind(fp2);
    if (fp1 = NULL)
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
void editProduct() //edit products
{
    struct Inventory *temp;
    int cd, f = 0;

    printf("\nEnter product code you want to edit :");
    scanf("%d", &cd);

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

    return 1;
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

//int loginpage()
//{
    //  struct loginCredential *pr;
    //  int ch, tempid;
    //  FILE *fptr;
    //  int choice;
    //  char AdminID[15];
    //  char upassword[12];
    //  printf("\nEnter 1 for AdminID:\n");
    //  printf("\nEnter 2 for UserID:\n");
    //  printf("\nEnter choice ");
    //  scanf("%d", &choice);

    //  if (choice == 1) // login for admin
    //  {

    //  printf("\nEnter AdminID:\n");
    //  scanf("%s", AdminID);

    //  printf("\nEnter password:\n");
    //  scanf("%s", upassword);

    //  if (strcmp(AdminID, "arun") == 0)
    //  {
    //      if (strcmp(upassword, "123") == 0)
    //      {

    //      printf("\nWelcome. LOGIN SUCCESS!");
    //      mainMenu(choice);
    //      }

    //      else
    //      {
    //      printf("\nWrong Password please try again");
    //      loginpage();
    //      }
    //  }
    //  else
    //  {
    //      printf("\nAdminID doesn't exist");
    //      loginpage();
    //  }
    //  }

    //  if (choice == 2) //login for user
    //  {

    //  printf("\nEnter 1 for New User\n");
    //  printf("\nEnter 2 for Existing User\n");
    //  printf("\nEnter choice: ");
    //  scanf("%d", &ch);
    //  if (ch == 1)
    //  {
    //      pr = (struct loginCredential *)malloc(sizeof(struct loginCredential));
    //      printf("\nenter new user id ");
    //      scanf("%d", &l.userid);

    //      printf("\nenter password");
    //      scanf("%s", l.password);
    //      //fflush(stdin);

    //   fptr = fopen ("userrecord.txt", "a");
    //   if (fptr == NULL)
    //  {
    //  fprintf(stderr, "\nError opening file\n");
    //  exit (1);
    //  }
    // fwrite(&l,sizeof(l),1,fptr);
    //  fclose(fptr);
    //      usercount++;
    //      printf("\nlogin successful,new user added....");
    //      mainMenu(choice);
    //  }
    //  else if (ch == 2)
    //  {
    //      printf("\nEnter userid");
    //      scanf("%d", &tempid);
    //      printf("\nEnter password");
    //      scanf("%s", upassword);

    //  }
    //  else
    //  {
    //      printf("\nenter valid choice");
    //      loginpage();
    //  }
    //  }
    //  return 1;
//}
