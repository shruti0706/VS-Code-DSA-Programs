//Write a Program to initialize array at compile time.
#include<stdio.h>
#include<conio.h>
void main()
{
    int i;
    int arr[]={2, 3, 4};    
    for(i=0; i<3; i++) {
        printf("%d ",arr[i]);
    }
    getch();
}