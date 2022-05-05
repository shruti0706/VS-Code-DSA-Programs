#include<stdio.h>
void main(){
int i, j,n=5 ;
clrscr();
for (i=0;i<n;i++){
	for(j=1;j<=n-i;j++){
	printf("%d",j);
}
printf("\n");
}
getch();
}