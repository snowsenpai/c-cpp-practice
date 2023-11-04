#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    srand(time(NULL));

    int nRange = 100;
    int answer = (rand() % nRange) + 1;

    int guess;
    bool correct;
    int nTries = 0;

    // Assets
    // ! debug, seg fault
    cout << "=+=+=+=+=+=+= Number Guessing Game =+=+=+=+=+=+=" << endl;
    cout << "=+=+=+=+=+=+=+=  You VS Computer =+=+=+=+=+=+=+=" << endl;

    // Game loop
    do
    {
        // Input
        cout << "Guess the number: ";
        cin >> guess;

        // ? hint1[] & hint2[]
        char hint[15];
        memcpy(hint, (guess > answer) ? "Guess is high" : "Guess is low", sizeof(hint));

        correct = guess == answer;
        if (!correct)
        {
            cout << "Wrong guess try again" << endl;
            cout << hint << endl;
            nTries++;
        }
    } while (!correct);

    // Render output
    cout << guess << " is correct" << endl;
    cout << "Number of tries: " << nTries << endl;

    // ! cmd closes without displaying result
    cin.get();
}