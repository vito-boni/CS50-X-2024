#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string fname = get_string ("What's your first name? ");

    printf ("Hello, %s\n\n", fname);
}
