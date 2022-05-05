// insertion sort
// descending order

#include <stdio.h>

void insertionSort(int a[50], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = i;
        for (j = key - 1; j >= 0; j--)
        {
            if (a[key] > a[j])
            {
                a[j] = a[j] + a[key] - (a[key] = a[j]);
                key = j;
            }
        }
    }
}

int main()
{
    int i, arr[50], n;
    // clrscr();
    printf("Enter total number of elements");
    scanf("%d", &n);
    printf("\nEnter %d elements-", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(&arr, n);

    printf("\narray after sorting - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // getch();
    return 0;
}