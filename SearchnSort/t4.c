// find sumofpairs number in given unsorted integer array

#include <stdio.h>

void sumofpairs(int a[], int n)
{
   
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i + 1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(a[i]+a[j]==a[k]){
                    printf("sum of %d & %d is %d\n",a[i],a[j],a[k]);
                }
            }
            
        }
    }
}
void bubblesort(int a[50], int n)
{
    int i, j, flag = 1;
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                a[i] = a[i] + a[i + 1] - (a[i + 1] = a[i]);
                flag = 1;
            }
        }
    }
}
int main()
{
    int arr[100];
    int i;
    int n;
    printf("Enter size of array- ");
    scanf("%d", &n);
    printf("Enter %d elements of array-", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubblesort(&arr, n);
    sumofpairs(arr, n);

    return 0;
}