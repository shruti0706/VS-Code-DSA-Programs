#include<stdio.h>
#include<conio.h>
int main(){
int i, j,k,n=5 ,t,c,f=0;
// clrscr();
for (i=1;i<=n;i++){
	t=1;
    c=65;
	for(k=i;k<n;k++){
		printf(" ");
	}
	for(j=1;j<i*2;j++){
	
	if(t==i)
	f=1;

	printf("%c",f==0?c++:c--);
    t++;
}
printf("\n");
f=0;
}
// getch();
}