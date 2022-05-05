//Stack Application : Brackets matching..
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10;
char stack[10];
char str[10];
int top = -1;

int main()
{
    int length,i;
    clrscr();

    printf("Enter parentheses to be matched\n");
    scanf("%s",str);
    length=strlen(str);
    if(length%2!=0)
    {
        printf("Imbalanced brackets...");
    }
    else{
        for(i=0;i<length/2;i++){
            stack[++top]=str[i];
        }
        for(i=length/2;i<length;i++){
    if(stack[top]=='('&&str[i]==')')
                top--;
        
                else if(stack[top]=='{'&&str[i]=='}')
                top--;
                else if(stack[top]=='['&&str[i]==']')
                top--;
                
        }
        if(top==-1){
            printf("brackets are balanced...");
        }
else{
     printf("Imbalanced brackets...");
}

    }


    getch();
    return 0;
}
