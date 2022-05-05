// quick sort
#include <stdio.h>

void quicksort(int a[], int l, int h)
{
    int pivot;
    if (l < h)
    {
        pivot = partition(a, l, h);
        quicksort(a, l, pivot - 1); // elements < pivot
        quicksort(a, pivot + 1, h); // elements > pivot
    }
    return;
}
int partition(int a[], int l, int h)
{
    int i = l + 1, j = h, pivot = l;
    do
    {
        while (a[i] < a[pivot])
            i++;
        while (a[j] > a[pivot])
            j--;
        if (i < j)
            a[i] = a[i] + a[j] - (a[j] = a[i]);

    } while (i < j);
    a[pivot] = a[pivot] + a[j] - (a[j] = a[pivot]);
    pivot = j;

    return pivot;
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
    quicksort(&arr, 0, n);
    // partition(&arr, 1, n - 1);
    printf("array after sorting - ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    getch();
    return 0;
}