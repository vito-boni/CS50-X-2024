/*
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid_one (string key);
void encipher(string key, string plaintext);

int main(int argc, string argv[]) {

    if (argc != 2 || !valid_one(argv[1])) { // negate the result of valid_one
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string plaintx = get_string("Plaintext: ");

    // TODO: Implement the substitiution cipher (encipher)
    // TODO: Print the enciphered txt
}

bool valid_one (string key){
    int letters[26] = {0};

    if (strlen(key) != 26) { // i put the '()' wrongly, fais attention.
        return false;
    }

    for (int i = 0; i < 26; i++) {

        if (!isalpha(key[i])) {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (letters[index] > 0) {
            return false; // don't forget ';' :)
        }

        letters[index]++;
    }

    return true; // and this one :)
}

void encipher(string key, string plaintext) {
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        if (isalpha(plaintext[i])) {
            char cipher = isupper(plaintext[i]) ? toupper(key[plaintext[i] - 'A']) : tolower(key[plaintext[i] - 'a']);
            printf("%c", cipher);
        } else {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}
*/

/*
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // oublies pas, pour atoi()


// vérifier si la clé est valide
bool validate_key(string key);

// Pour effectuer la rotation de César sur un caractère, la fonction
char rotate(char c, int n);

int main(int argc, string argv[]){

    // si le bon nombre d'arguments est fourni
    if (argc != 2 || !validate_key(argv[1])){
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // convertir la clé en un entier
    int clé = atoi(argv[1]);

    // obtenir le texte en clair de l'utilisateur
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // chiffrer le texte en clair
    for (int i = 0, n = strlen(plaintext); i < n; i++){
        printf("%c", rotate(plaintext[i], clé));
    }

    printf("\n");
    return 0;
}

// une fonction pour vérifier si une chaîne contient uniquement des chiffres
bool only_digits(string s){
    for (int i = 0, n = strlen(s); i < n; i++){
        if (!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

// pour effectuer la rotation de César sur un caractère
char rotate(char c, int n){
    if (isalpha(c)){
        char a = isupper(c) ? 'A' : 'a';
        return ((c - a + n) % 26) + a;
    }
    return c;
}

*/
