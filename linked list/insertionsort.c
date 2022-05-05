//insertion sort
#include <stdio.h>

void main()
{
    int arr[100];
    int n, i, j, v;

    printf("enter the number of elements: ");
    scanf("%d", &n);

    printf("Input %d element in the array :\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d : ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                v = arr[i];
                arr[i] = arr[j];
                arr[j] = v;
            }
        }
    }

    printf("\nsorted list:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}