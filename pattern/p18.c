#include<stdio.h>
#include<conio.h>
int main(){
int i, j,k,n=5 ,t,f=0;
// clrscr();
for (i=n;i>=1;i--){
	t=1;
	for(k=i;k<n;k++){
		printf(" ");
	}
	for(j=1;j<i*2;j++){
	
	if(t==i)
	f=1;
	
	printf("%d",f==0?t++:t--);
}
printf("\n");
f=0;
}
// getch();
}