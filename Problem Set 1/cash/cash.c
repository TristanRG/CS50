#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;

    do
    {
        change = get_int("Changed owed: ");
    }
    while (change <= 0);

    int coins = 0;

    coins += change / 25;
    change %= 25;

    coins += change / 10;
    change %= 10;

    coins += change / 5;
    change %= 5;

    coins += change;

    printf("%d\n", coins);
}
