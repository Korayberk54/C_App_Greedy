#include <cs50.h>
#include <stdio.h>
#include <math.h>

float dollars;
int coins = 0;

void greedy();
int get_change();

int main()
{
    get_change();
    greedy();

}

int get_change()
{
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    return dollars;

}

void greedy()
{
    int cents = round(dollars * 100);
    while (cents != 0)
    {
        coins += cents / 25;
        cents %= 25;

        coins += cents / 10;
        cents %= 10;

        coins += cents / 5;
        cents %= 5;

        coins += cents / 1;
        cents %= 1;
    }

    printf("%d\n",coins);
}
