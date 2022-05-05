// to split sentence for a given character

#include <stdio.h>
#include <string.h>
int main()
{
    int flag;
    char str[50] = "hellostarssee theshine";
    char *token = strtok(str, "s");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "s");
    }

    return 0;
}