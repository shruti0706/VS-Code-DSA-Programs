//to know frequency of each character in sentence

#include <stdio.h>
#include <string.h>
int main()
{
    int flag;
    char str[50]="hellostars";
    char ch='s';
    int count=0;
    // printf("Enter string- ");
    // scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if( ch == str[i])
        {
            count++;
        }
    }
        printf("the given char occurred %d times in string",count);
    

    return 0;
}