#include <iostream>
using namespace std;

int main() {
    string answer;

    cout << "? Hey Sameeksha ?\n\n";
    cout << "From the moment you came into my life,\n";
    cout << "you made everything feel warmer, calmer, and brighter.\n\n";

    cout << "Every smile of yours means the world to me,\n";
    cout << "and every moment with you feels special ??\n\n";

    cout << "So today, with all my heart, I want to ask you something...\n\n";
    cout << "?? Sameeksha, will you be mine forever? (yes/no): ";
    cin >> answer;

    if (answer == "yes" || answer == "Yes" || answer == "YES") {
        cout << "\n?? YESSSS!!! ??\n";
        cout << "You just made my heart the happiest it has ever been ??\n";
        cout << "I promise to cherish you, support you,\n";
        cout << "and walk beside you in every phase of life ??\n";
        cout << "Forever starts now ??\n";
    } else {
        cout << "\n?? Thank you for listening, Sameeksha.\n";
        cout << "No matter what, you will always hold a special place in my heart ??\n";
    }

    cout << "\n?? Always & Forever ??\n";
    return 0;
}
