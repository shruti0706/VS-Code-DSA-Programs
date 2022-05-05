// find missing number in a given integer array of 1 to 100
#include <stdio.h>

void missingArray(int a[], int n)
{
    int sum = (n * (n + 1)) / 2;
    int isum = 0;

    for (int i = 0; i < n-1; i++)
    {
        isum = isum + a[i];
    }
    printf("missing numner is : %d ",sum-isum);
    
}

int main()
{
    int arr[100];
    int i, j;
    int n;
    printf("Enter size of array");
    scanf("%d", &n);
    printf("Enter %d elements of array", n - 1);

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    missingArray(arr, n);

    return 0;
}