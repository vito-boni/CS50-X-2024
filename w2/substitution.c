/*
Objectives:
- When typed './substitution' and all the 26 letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ),
  prompt the user for the plain text. And then, Plain text → Cipher text (ABC → JTR)
- If the user didn't put any key after './substitution', promt 'Usage: ./substitution KEY'
- If typed fewer than 26 letters, prompt 'Key must contain 26 characters'
- Anything but numbers. If there's a number, prompt 'Key must only contain Alphabetical char.
- No repeated characters. If there's one, prompt 'Key must not contain repeated characters'.
- Make it case insensitive. (Hello. I'm Vi! → Vklln. O'p Bo!)
- JBCDEFGHIKLMNOPQRSTUVWXYZA
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// vérifier si la clé est valide
bool validate_key(string key);

int main(int argc, string argv[]){
    // si le bon nombre d'arguments est fourni
    if (argc != 2 || !validate_key(argv[1])){
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // obtenir le texte en clair de l'utilisateur
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // chiffrer le texte en clair
    for (int i = 0, n = strlen(plaintext); i < n; i++){
        if (isalpha(plaintext[i])){
            char a = isupper(plaintext[i]) ? 'A' : 'a';
            printf("%c", isupper(plaintext[i]) ? toupper(argv[1][plaintext[i] - a]) : tolower(argv[1][plaintext[i] - a]));
        } else {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
    return 0;
}

// une fonction pour vérifier si une chaîne contient uniquement des chiffres
bool validate_key(string key){
    int freq[26] = {0};

    if (strlen(key) != 26){
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0; i < 26; i++){
        if (!isalpha(key[i])){
            printf("Key must only contain alphabetical characters.\n");
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (freq[index] > 0){
            printf("Key must not contain repeated characters.\n");
            return false;
        }

        freq[index]++;
    }

    return true;
}
