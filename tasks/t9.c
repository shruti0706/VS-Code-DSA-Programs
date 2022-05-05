// roman to decimal conversion

#include <stdio.h>
#include <string.h>

int digit(char);

int main()
{

    char romn[1000];
    int i = 0;
    long int number = 0;

    printf("Enter any roman number (Valid digits are I, V, X, L, C, D, M):  \n");
    scanf("%s", romn);

    while (romn[i])
    {

        if (digit(romn[i]) < 0)
        {
            printf("Invalid roman digit : %c", romn[i]);
            return 0;
        }

        if ((strlen(romn) - i) > 2)
        {
            if (digit(romn[i]) < digit(romn[i + 2]))
            {
                printf("Invalid roman number");
                return 0;
            }
        }

        if (digit(romn[i]) >= digit(romn[i + 1]))
            number = number + digit(romn[i]);
        else
        {
            number = number + (digit(romn[i + 1]) - digit(romn[i]));
            i++;
        }
        i++;
    }

    printf("Its decimal value is : %ld", number);

    return 0;
}

int digit(char c)
{

    int value = 0;

    switch (c)
    {
    case 'I':
        value = 1;
        break;
    case 'V':
        value = 5;
        break;
    case 'X':
        value = 10;
        break;
    case 'L':
        value = 50;
        break;
    case 'C':
        value = 100;
        break;
    case 'D':
        value = 500;
        break;
    case 'M':
        value = 1000;
        break;
    case '\0':
        value = 0;
        break;
    default:
        value = -1;
    }

    return value;
}