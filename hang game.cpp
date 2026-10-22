#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string word = "computer";
    string guessed(word.length(), '_');

    vector<char> wrongGuesses;
    int attempts = 6;
    char guess;

    cout << "=============================\n";
    cout << "       HANGMAN GAME\n";
    cout << "=============================\n";

    while (attempts > 0 && guessed != word) {

        cout << "\nWord: ";
        for (char c : guessed) {
            cout << c << " ";
        }

        cout << "\nAttempts left: " << attempts;

        cout << "\nWrong guesses: ";
        for (char c : wrongGuesses) {
            cout << c << " ";
        }

        cout << "\n\nEnter a letter: ";
        cin >> guess;

        // Convert uppercase to lowercase
        guess = tolower(guess);

        // Check if already guessed
        if (guessed.find(guess) != string::npos ||
            find(wrongGuesses.begin(), wrongGuesses.end(), guess) != wrongGuesses.end()) {
            cout << "You already guessed that letter!\n";
            continue;
        }

        bool found = false;

        // Check the letter in the word
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                found = true;
            }
        }

        if (found) {
            cout << "Correct guess!\n";
        } else {
            cout << "Wrong guess!\n";
            wrongGuesses.push_back(guess);
            attempts--;
        }
    }

    cout << "\n=============================\n";

    if (guessed == word) {
        cout << "?? Congratulations! You won!\n";
        cout << "The word was: " << word << endl;
    } else {
        cout << "?? Game Over!\n";
        cout << "The correct word was: " << word << endl;
    }

    cout << "=============================\n";

    return 0;
}
