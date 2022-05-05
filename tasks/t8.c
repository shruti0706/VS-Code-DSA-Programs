// number guessing game
#include <stdio.h>

int main()
{
    int num = 100;
    int n = 20;
    int temp, count = 1;
    printf("\nMachine:Guess a number between 1 and %d\nPlayer:", num);
    scanf("%d", &temp);
    while (temp != n)
    {
        if (temp > n)
            printf("\nMachine:Lower number please!\nPlayer:");
        if (temp < n)
            printf("\nMachine:Higher number please!\nPlayer:");
        scanf("%d", &temp);
        count++;
    }
    printf("\nMachine:You guessed the number in %d attempts", count);
}