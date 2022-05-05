// linear search-type 2
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
//printing all array elements

    printf("\nThe given array is - ");

    for (i = 0; i < n; i++)
    { 
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element you want to search- ");
    scanf("%d", &e);
    //searching element
    if (e == arr[n / 2])
    {
        printf("\nElement found at position %d", (n / 2) + 1);
        flag = 1;
    }
    else
    {
        for (i = 0, j = n; i<n / 2, j> n / 2; i++, j--)
        {
            if (e == arr[i])
            {
                printf("\nElement found at position %d", i + 1);
                flag = 1;

                break;
            }
            if (e == arr[j])
            {
                printf("\nElement found at position %d", j + 1);
                flag = 1;

                break;
            }
        }
    }
    if (flag == 0)
        printf("\nentered element not found ");

    // getch();
    return 0;
}