// bubble sort
// pushing large elements at last 
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
    int i, arr[50], n;
    // clrscr();
    printf("Enter total number of elements");
    scanf("%d", &n);
    printf("Enter %d elements-",n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(&arr, n);
    printf("array after sorting -\n ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // getch();
    return 0;
}