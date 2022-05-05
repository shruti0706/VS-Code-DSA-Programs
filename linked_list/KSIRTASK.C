#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct list
{
    struct list *left;
    int rdata;
    int ldata;
    struct list *right;
} *head = NULL, *rcur = NULL, *lcur = NULL;

void adddata(int n);
void adddataleft();
void printheadlist();
void printlist(int n);
void pl(){
    struct list * t;
    t=head->right;
    while(t!=NULL){
        printf("\n%d",t->ldata);
        t=t->left;
    }
    
}
int main()
{

    int num;
    // clrscr();
    printf("Enter the number ");
    scanf("%d", &num);
    adddata(num);
    //printheadlist();
    adddataleft();
   // printlist(num);
pl();
    //  getch();
    return 0;
}
void adddata(int n)
{
    struct list *h;
    int count = 1, f = 0, t = n, rdata;

    while (count != n * 2)
    {
        rdata = f == 0 ? t-- : t++;
        h = (struct list *)malloc(sizeof(struct list));
        h->rdata = rdata;
        if (t == 1)
            f = 1;
        if (head == NULL)
        {
            head = rcur = h;
        }
        else
        {
            rcur->right = h;
            rcur = h;
        }
        count++;
    }
    printf("\n");
}
void adddataleft()
{
    struct list *t, *h = head;
    int n;
    while (h != NULL)
    {
        n = h->rdata;
        lcur = h;

        while (n != 0)
        {

            t = (struct list *)malloc(sizeof(struct list));
            t->ldata = --n;
            t->left = NULL;

            lcur->ldata = t->ldata;
            lcur->left = t;
            lcur = t;
        }
        h = h->right;
    }
}
void printheadlist()
{

    struct list *t = head, *h = head;
    while (h != NULL)
    {
        printf("%d", h->rdata);
        h = h->right;
    }
}
void printlist(int n)
{

    struct list *t, *h;
    h = head;
    t = h;
    printf("\n");
    n = n - 1;

    while (h != NULL)
    {
        t = h;
        printf("%d", t->ldata);
        h = h->right;
    }
    h = head;
    printf("\n");
    while (h != NULL)
    {
        t = h->left;
        printf("%d", t->ldata);
        h = h->right;
    }
    h = head;
    printf("\n");
    while (h != NULL)
    {
        t = h->left->left;
        printf("%d", t->ldata);
        h = h->right;
    }
    h = head;
    printf("\n");
    while (h != NULL)
    {
        t = h->left->left->left;
        printf("%d", t->ldata);
        h = h->right;
    }

    h = head;
    printf("\n");
    while (h != NULL)
    {
        t = h->left->left->left->left;
        printf("%d", t->ldata);
        h = h->right;
    }
}