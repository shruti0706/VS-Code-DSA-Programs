#include<stdio.h>
void main(){
int i, j,n=5 ;
clrscr();
for (i=0;i<n;i++){
	for(j=n-i;j>=1;j--){
	printf("%d",j);
}
printf("\n");
}
getch();
}