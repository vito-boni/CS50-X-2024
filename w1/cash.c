//quarters, dimes, nickels, pennies

#include <cs50.h>
#include <stdio.h>

int main()
{
    int x;
    do {
        x = get_int("\nChange owed: ");
    } while (x <= 0 || x > 9999);

    printf("%i¢\n\n", x);

    int q = 25, d = 10, n = 5, p = 1;
    int qq = 0, dd = 0, nn = 0, pp = 0;

    // Calculate the number of coins
    while (x >= q) {
        x -= q;
        qq++;
    }

    while (x >= d) {
        x -= d;
        dd++;
    }

    while (x >= n) {
        x -= n;
        nn++;
    }

    while (x >= p) {
        x -= p;
        pp++;
    }

    int all = qq + dd + nn + pp;

    printf("Your changes are: %i quarters, %i dimes, %i nickels, and %i pennies.\nHere are your %i coins. Have a good day!\n\n", qq, dd, nn, pp, all);

    return 0;
}
