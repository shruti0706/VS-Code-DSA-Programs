
#include <stdio.h>

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
    int i, e, arr[50], flag = 0, n;
    // clrscr();
    printf("Enter total number of elements- ");
    scanf("%d", &n);

    printf("\nEnter %d elements-", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //sorting array
    bubblesort(&arr, n);

    // printing all array elements
    printf("\nThe given array is - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element you want to search- ");
    scanf("%d", &e);
    // searching element
    if (e == arr[n / 2])
    {
        printf("\nElement found at position %d", (n / 2) + 1);
        flag = 1;
    }
    else if (e < arr[n / 2])
    {
        for (i = 0; i < n / 2; i++)

        {
            if (e == arr[i])
            {
                printf("\nElement found at position %d", i + 1);
                flag = 1;
                break;
            }
        }
    }
    else
    {
        for (i = n / 2; i < n; i++)
        {
            if (e == arr[i])
            {
                printf("\nElement found at position %d", i + 1);
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