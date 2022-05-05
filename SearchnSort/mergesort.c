// Merge sort
#include <stdio.h>

void mergesort(int arr[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;

        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);

        merge(arr, l, mid, h);
    }

    return;
}
int merge(int arr[], int l, int mid, int h)
{
    int i, j, k;
    int size1 = mid - l + 1;
    int size2 = h - mid;
    int a[25], b[25];
    for (i = 0; i < size1; i++)
    { 
        a[i] = arr[l + i];
    }
    for (i = 0; i < size2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < size1 && j < size2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
	}
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < size1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < size2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }

    return 0;
}

int main()
{
    int i, arr[50], n;
    clrscr();
    printf("Enter total number of elements");
    scanf("%d", &n);
    printf("Enter %d elements-", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("array before sorting - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    mergesort(arr, 0, n-1);

    printf("\narray after sorting - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    getch();
    return 0;
}