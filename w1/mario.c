#include <cs50.h>
#include <stdio.h>

void plus (int plus);

int main (void)
{
    int v;

    // terms
    do
    {
        v = get_int ("Height: ");
    }
    while (v < 1 || v > 8);

    // the pyramid
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v - i; j++)
        {
            printf(" ");
        }
        plus(i);

        printf("  ");
        plus(i);

        printf("\n");
    }
}

void plus (int plus)
{
    for (int k = 1; k <= plus; k++)
    {
        printf("#");
    }
}
