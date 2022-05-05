//program to print value of a variable using pointer variable

#include <stdio.h>
int main()
{
   
   int *p;

   int var = 10;

  
   p= &var;

   printf("Value of variable var is: %d", *p);
   printf("\nAddress of variable var is: %d", p);
   return 0;
}