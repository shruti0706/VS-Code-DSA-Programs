//bubble sort

#include <stdio.h>
int main()
{
    int a[100], i, n, ptr, j;
    printf("enter number of elements");
    scanf("%d", &n);
    printf("enter elements in the list");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                ptr = a[j];
                a[j] = a[j + 1];
                a[j + 1] = ptr;
            }
        }
    }
    printf("sorted list:");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}