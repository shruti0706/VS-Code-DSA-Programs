#include<stdio.h>
#include<conio.h>
int main(){
int i, j,k,n=4 ,t,f=0;
// clrscr();
for (i=1;i<=n;i++){
	t=1;
	for(k=i;k<n;k++){
		printf(" ");
	}
	for(j=1;j<i*2;j++){
	
	if(t==i)
	f=1;
	if(j%2==0){
    printf(" ");
    f==0?t++:t--;
    }
    else
	printf("%d",f==0?t++:t--);
}
printf("\n");
f=0;
}
// getch();
}