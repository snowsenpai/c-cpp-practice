#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // seed for rand
    srand(time(NULL));

    // variables: answer, user's guess, no of guesses

    int nRange = 100;
    int answer = (rand() % nRange) + 1;

    int guess;
    bool correct;
    int nTries = 0;

    // Assets
    printf("=+=+=+=+=+=+= Number Guessing Game =+=+=+=+=+=+=\n");
    printf("=+=+=+=+=+=+=+=  You VS Computer =+=+=+=+=+=+=+=\n");

    // Game loop
    do
    {
        // Input

        // * Difficulty, varying nRange

        printf("Guess the number: ");
        scanf("%d", &guess);

        // Game logic

        char hint[15];
        memcpy(hint, (guess > answer) ? "Guess is high" : "Guess is low", sizeof(hint));

        correct = guess == answer;
        if (!correct)
        {
            printf("Wrong guess try again\n");
            printf("%s\n", hint);
            nTries++;
        }
    } while (!correct);

    // Render Output
    printf("%d is correct!!\n", guess);
    printf("Number of tries: %d\n", nTries);

    // ! cmd closes without displaying result
    getchar();
}