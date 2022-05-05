#include <iostream>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void bubblesort(int a[], int n, bool (&cmp)(int a, int b))
{
    for (int itr = 0; itr < n - 1; itr++)
    {
        for (int i = 0; i < n - itr - 1; i++)
        {
            if (cmp(a[i], a[i + 1]))
                swap(a[i], a[i + 1]);
        }
    }
}
int main()
{
    int n = 9;
    int arr[] = {4, 5, 3, 1, 8, 6, 2, 9, 7};
  cout<<"before sort"<<endl;
    for (int i : arr)
        cout << i << " ";
          bubblesort(arr, n, compare);
        cout<<endl<<"after sort"<<endl;
           for (int i : arr)
        cout << i << " ";
}