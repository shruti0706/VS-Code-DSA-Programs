// selection sort
// pushing smallest to first
#include <stdio.h>

void selectionSort(int a[50], int n)
{
    int i, j, smallest;

    for (i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }

        a[i] = a[i] + a[smallest] - (a[smallest] = a[i]);
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
    selectionSort(&arr, n);

    printf("\narray after sorting - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // getch();
    return 0;
}