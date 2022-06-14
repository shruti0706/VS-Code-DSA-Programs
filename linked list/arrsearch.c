//prgram to search an element in 1D array
#include <stdio.h>
 
int main()
{
    int arr[10] ;
    int i, num;
       
      for(i=0;i<10;i++){
          printf("enter the value for number %d-",i);
          scanf("%d",&arr[i]);
      }
    printf("enter the number you want to search");
    scanf("%d", &num);
    for (i = 0; i < 10; i++)
    {
        if (num == arr[i])
        {
            printf("Element found");
            break;
        }
    }
    if(i==10){
        printf("Element not found");
    }
    return 0;
}
