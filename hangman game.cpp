#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string getRandomWord() {
    vector<string> words = {"doctor", "computer", "hangman", "jabalpur", "biology", "anime", "science"};
    srand(time(0));
    return words[rand() % words.size()];
}

int main() {
    string word = getRandomWord();
    string guessed(word.length(), '_'); // Hidden word with underscores
    int attempts = 6; // Number of wrong attempts allowed
    vector<char> wrongGuesses;

    cout << "?? Welcome to Hangman! ??" << endl;
    cout << "Guess the word. You have " << attempts << " wrong attempts." << endl;

    while (attempts > 0 && guessed != word) {
        cout << "\nWord: " << guessed << endl;
        cout << "Wrong guesses: ";
        for (char c : wrongGuesses) cout << c << " ";
        cout << "\nAttempts left: " << attempts << endl;

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            wrongGuesses.push_back(guess);
            attempts--;
            cout << "? Wrong guess!" << endl;
        } else {
            cout << "? Good guess!" << endl;
        }
    }

    if (guessed == word) {
        cout << "\n?? Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\n?? Game Over! The word was: " << word << endl;
    }

    return 0;
}

