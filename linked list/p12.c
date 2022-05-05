//declare 2 level of pointer and print value of a variable using that

#include<stdio.h>
int main(){
    
    int var = 10; 
    int* p;
    int** ptr;

     p=&var;
      ptr = &p;
      printf("Value of variable var using pointer ptr = %d\n", **ptr); 
    return 0;

}