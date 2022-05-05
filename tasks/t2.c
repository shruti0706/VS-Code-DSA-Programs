// find duplicate number in given integer array

#include <stdio.h>

void duplicate(int a[], int n)
{
    printf("duplicate numbers - ");

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                printf("\n%d ", a[j]);
                break;
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

    duplicate(arr, n);

    return 0;
}