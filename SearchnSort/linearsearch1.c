// linear search-type 1
#include <stdio.h>
int main()
{
    int i, j, e, arr[50], flag = 0, n;
    // clrscr();
    printf("Enter total number of elements- ");
    scanf("%d", &n);
    printf("\nEnter %d elements-", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nThe given array is - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element you want to search- ");
    scanf("%d", &e);

    for (i = 0; i < n; i++)
    {
        if (e == arr[i])
        {
            printf("\nElement found at position %d", i + 1);
            flag = 1;
        }
    }
        if (flag == 0)
            printf("\nentered element not found ");

        // getch();
        return 0;
    }