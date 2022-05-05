//prgram to initialize elements of array in runtime
#include <stdio.h>

int main()
{
    int arr[10];
    int i;

    for (i = 1; i < 11; i++)
    {
        printf("enter the value for number %d-", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}