//seach a substring in a given string

#include <stdio.h>
#include <string.h>
int main()
{
    int flag;
    char str[50];
    char ss[20];
    printf("Enter string- ");
    scanf("%s", str);
    printf("Enter substring to be searched- ");
    scanf("%s", ss);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (ss[0] == str[i])
        {
            for (int j = 1; ss[j] != '\0'; j++)
            {
                flag = 0;
                if (ss[j] == str[i + j])
                    flag = 1;
            }
        }
    }
    if (flag)
        printf("found");
    else
        printf(" not found");

    return 0;
}