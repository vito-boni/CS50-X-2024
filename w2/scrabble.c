/*
Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word.
Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // Ajouté ici

int compute_score(string word);

int main() {

    string j1 = get_string("\nJouer Un : ");
    string j2 = get_string("Jouer Deux : "); // typo…

    int score1 = compute_score(j1);
    int score2 = compute_score(j2);

    if (score1 > score2){
        printf("Player 1 wins!\n");
    }

    else if (score2 > score1){
        printf("Player 2 wins!\n");
    }
    else {
        printf("Tie\n"); // oublies pas le ';' :)
    }

    printf("\n");

    return 0;

}

int compute_score(string word)
{
    int score = 0;

    // pour chaque char, notez-les.
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
