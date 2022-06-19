//decimal to octal
#include<stdio.h>
  
int main(){
int octn[10],n,i=0,j;
printf("enter decimal number: ");
scanf("%d",&n);
  
while(n!=0){
    octn[i++]=n%8;
    n=n/8;
}
printf("octal number: ");
for(j=i-1;j>0;j--)
printf("%d",octn[j]);


}
