// find smallestandlargest number in given unsorted integer array

#include <stdio.h>

void smallestandlargest(int a[], int n)
{
int l,s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
             l = a[i];
             s = a[i];
            if (a[j] < a[i])
            {
                s = a[j];
            }
            if (a[j] > a[i])
            {
                l = a[j];
            }
        }
    }
    printf("smallest number = %d \nargest number = %d ",s,l);

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

    smallestandlargest(arr, n);

    return 0;
}