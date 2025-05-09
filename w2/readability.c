/*
You’ll implement a program that calculates the approximate grade level needed to comprehend some text.
Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer.
If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number.
If the grade level is less than 1, your program should output “Before Grade 1”.
*/

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(){

    // prompt the user for the text
    string text = get_string("Text: ");

    // count the numbers of the letters, words, and sentences in the text.
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // L and S = …
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // compute the coleman liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // define the grades
    char *grades[] = {"Before Grade 1", "Grade 1", "Grade 2", "Grade 3", "Grade 4", "Grade 5", "Grade 6", "Grade 7", "Grade 8", "Grade 9", "Grade 10", "Grade 11", "Grade 12", "Grade 13", "Grade 14", "Grade 15", "Grade 16", "Grade 16+"};

    // print the grade level
    if (index < 1){
        printf("%s\n", grades[0]);

    } else if (index >= 1 && index <= 17){
        printf("%s\n", grades[index]);

    } else {
        printf("%s\n", grades[17]);
    }
}


int count_letters(string text){
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++){
        if (isalpha(text[i])){
            letters++;
        }
    }
    return letters;
}

int count_words(string text){
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++){
        if (text[i] == ' '){
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string text){
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++){
        if (text[i] == '.' || text[i] == '!' || text[i] == '?'){
            sentences++;
        }
    }
    return sentences;
}

/*
to make it loop:
while (true){

    if (text == NULL){
        break;
    }
}
*/
