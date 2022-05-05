#include <stdio.h>
#include <conio.h>
int main()
{
    int i, j, n = 4, t = 65;
    // clrscr();
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= i; j++)
        {

            printf("%c ", t);
        }
            t++;
        
        printf("\n");
    }
    // getch();
}