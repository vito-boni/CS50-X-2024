#include <cs50.h>
#include <stdio.h>
#include <ctype.h> // Include the ctype.h library for character validation

// Function to check if the input contains only digits
bool is_valid_input(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    string card_number;

    do
    {
        card_number = get_string("Enter your credit card number: ");

        // Check if the input contains only digits
        if (!is_valid_input(card_number)) {
            printf("Invalid input! Please enter digits only.\n");
        }
    }
    while (!is_valid_input(card_number));

    // Now you can proceed with further processing based on the valid card number
    // (e.g., implementing Luhn's algorithm to validate the card number).

    return 0;
}
