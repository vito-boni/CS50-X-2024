/*
A program that enables you to encrypt messages using Caesar’s cipher (A → C, B → D, …).
At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime.
We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[]){

    // valider l'argument
    if (argc != 2 || !only_digits(argv[1])){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert la clef à integer
    int clef = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: "); // 'ciphertext', not cyphertext :)

    // demand un plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++){
        printf("%c", rotate(plaintext[i], clef));
    }

    printf("\n");
    return 0;
}

// seulment en digit
bool only_digits(string s){
    for (int i = 0, n = strlen(s); i < n; i++){
        if (!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

char rotate(char c, int n){
    if (isalpha(c)){
        char a = isupper(c) ? 'A' : 'a';
        return ((c - a + n) % 26) + a;
    }
    return c;
}
