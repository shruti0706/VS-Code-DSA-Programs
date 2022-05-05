//radix sort
#include<stdio.h>
int max(int a[], int n)
{
      int max = a[0], i;
      for(i = 1; i < n; i++)
      {
            if(max < a[i])
            max = a[i];
      }
      return max;
}

void RadixSort(int a[], int n)
{
      int bucket[10][10], bucket_cnt[10];
      int i, j, k, r, NOP=0, divisor=1, lar, pass;
      lar=max(a, n);
      printf("\n The largest element is : %d\n",lar);
      while(lar > 0)
      {
            NOP++;
            lar/=10;
      }
      
      for(pass = 0; pass < NOP; pass++)
      {
            for(i = 0; i < 10; i++)
            {
                  bucket_cnt[i] = 0;
            }
         
            for(i = 0; i < n; i++)
            {
                  r = (a[i] / divisor) % 10;
                  bucket[r][bucket_cnt[r]] = a[i];
                  bucket_cnt[r] += 1;
            }
          
            i = 0;
            for(k = 0; k < 10; k++)
            {
                  for(j = 0; j < bucket_cnt[k]; j++)
                  {
                        a[i] = bucket[k][j];
                        i++;
                  }
            }
            divisor *= 10;
            printf("\n Numbers after completing pass %d :\n",pass+1);
            for(i = 0; i < n; i++)
                  printf("  %d",a[i]);
            printf("\n");
      }
}

int main()
{
      int i, n, a[10];
      printf(" How many numbers you want to sort?: ");
      scanf("%d",&n);
      printf("\n Enter %d numbers:\n",n);
      for(i = 0; i < n; i++)
      {
            scanf("%d",&a[i]);
      }
      RadixSort(a,n);
      printf("\n Sorted numbers after using radix sort:\n");
      for(i = 0; i < n; i++)
            printf("  %d",a[i]);
      printf("\n");
      return 0;
}