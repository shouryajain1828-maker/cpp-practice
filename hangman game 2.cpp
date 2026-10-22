// hangman.cpp
#include <bits/stdc++.h>
using namespace std;

const vector<string> WORDS = {
    "computer", "hangman", "programming", "variable", "function",
    "algorithm", "keyboard", "internet", "compiler", "debugger"
};

const vector<string> HANGMAN_PICS = {
      R"(
     +---+
     |   |
         |
         |
         |
         |
    =======)",
    R"(
     +---+
     |   |
     O   |
         |
         |
         |
    =======)",
    R"(
     +---+
     |   |
     O   |
     |   |
         |
         |
    =======)",
    R"(
     +---+
     |   |
     O   |
    /|   |
         |
         |
    =======)",
    R"(
     +---+
     |   |
     O   |
    /|\  |
         |
         |
    =======)",
    R"(
     +---+
     |   |
     O   |
    /|\  |
    /    |
         |
    =======)",
    R"(
     +---+
     |   |
     O   |
    /|\  |
    / \  |
         |
    =======)"
};

string pick_random_word() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, (int)WORDS.size()-1);
    return WORDS[dis(gen)];
}

string to_lower_str(const string &s) {
    string out = s;
    transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

void display_state(const string &secret, const set<char> &guessed, int wrongs) {
    cout << HANGMAN_PICS[min(wrongs, (int)HANGMAN_PICS.size()-1)] << "\n\n";
    // show word with underscores
    for (char c : secret) {
        if (guessed.count(c)) cout << c << ' ';
        else cout << "_ ";
    }
    cout << "\n\n";
    // show guessed letters
    cout << "Guessed letters: ";
    for (char c : guessed) cout << c << ' ';
    cout << "\n\n";
}

bool word_guessed(const string &secret, const set<char> &guessed) {
    for (char c : secret)
        if (!guessed.count(c)) return false;
    return true;
}

int main() {
    cout << "=== Hangman Game ===\n\n";
    string secret = pick_random_word();
    secret = to_lower_str(secret);

    set<char> guessed;
    set<char> wrong_guesses;
    int max_wrong = (int)HANGMAN_PICS.size() - 1;
    int wrongs = 0;

    // reveal first and last letter optionally (comment out if not desired)
    // guessed.insert(secret.front());
    // guessed.insert(secret.back());

    while (true) {
        display_state(secret, guessed, wrongs);

        if (word_guessed(secret, guessed)) {
            cout << "Congratulations! You guessed the word: " << secret << "\n";
            break;
        }

        if (wrongs >= max_wrong) {
            cout << "You lost. The word was: " << secret << "\n";
            break;
        }

        cout << "Enter a letter (or type the full word): ";
        string input;
        if (!getline(cin, input)) break;
        if (input.empty()) {
            cout << "Please enter something.\n";
            continue;
        }

        // trim and lowercase
        input = to_lower_str(input);
        // remove spaces
        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        // player typed full word
        if (input.size() > 1) {
            if (input == secret) {
                cout << "\nCorrect! You guessed the whole word!\n";
                break;
            } else {
                cout << "Wrong guess of the whole word.\n";
                wrongs++;
                continue;
            }
        }

        char guess = input[0];
        if (!isalpha(guess)) {
            cout << "Please enter an alphabetic character.\n";
            continue;
        }

        if (guessed.count(guess) || wrong_guesses.count(guess)) {
            cout << "You already guessed '" << guess << "'. Try another letter.\n";
            continue;
        }

        // check if letter in secret
        if (secret.find(guess) != string::npos) {
            guessed.insert(guess);
            cout << "Good! '" << guess << "' is in the word.\n";
        } else {
            wrongs++;
            wrong_guesses.insert(guess);
            cout << "Sorry, '" << guess << "' is not in the word. Wrong guesses: " << wrongs << "/" << max_wrong << "\n";
        }
    }

    cout << "\nThanks for playing Hangman!\n";
    return 0;
}

