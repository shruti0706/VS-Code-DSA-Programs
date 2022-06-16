//binary search
#include<stdio.h>
int main()
{ 
    int n,i,num,first,last,mid;
    printf("enter no. 0f elements in elements :");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nenter elements in ascending order:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nelements in array");
    for(i=1;i<=n;i++)
    {
        printf("\n%d",arr[i]);
    }
    printf("\nenter the element to be search :");
    scanf("%d",&num);
    first=1;
    last=n;
       mid=(first+last)/2;
     
       
    if(num==arr[mid])
       printf("search value find in middle");
    
    else if(num<arr[mid])
    {
        last=mid-1;    
        for(i=1;i<=last;i++)
       {
           if(arr[i]==num)
           {
                printf("element %d found at %d position",num,i);
                break;
           }
        
       }
    }
    else if(num>arr[mid])
    {
        first=mid+1;
        for(i=first;i<=last;i++)
       {
           if(arr[i]==num)
           {
                printf("element %d found at %d position",num,i);
                break;
           }
        
       }
    }
    else
      printf("not found");
    return 0;
}
