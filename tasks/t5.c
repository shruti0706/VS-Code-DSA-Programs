// remove duplicate number in given integer array

#include <stdio.h>

void duplicate(int a[], int n)
{
    int flag = 0;
    a[n] = '/0';
    for (int i = 0; a[i] != '/0'; i++)
    {
        if (a[i] == a[i + 1])
        {
            flag = 1;
            for (int j = i + 1; a[j] != '/0'; j++)
            {
                a[j] = a[j + 1];
            }
        }
    }
    if (flag == 1)
    {
        // flag=0;
        duplicate(a, n);
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

    bubblesort(arr, n);
    duplicate(arr, n);
    printf("array after removing duplicate elemnets : ");
    for (i = 0; arr[i] != '/0'; i++)
    {
        printf(" %d ", arr[i]);
    }
    return 0;
}