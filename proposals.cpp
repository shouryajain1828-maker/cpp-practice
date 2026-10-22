#include <iostream>
#include <windows.h> // For Sleep() — works on Windows. Use "unistd.h" with sleep() on Linux/Mac.
using namespace std;

void typeEffect(string text, int delay = 80) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delay);
    }
    cout << endl;
}

int main() {
    system("color 0C"); // Red text color

    typeEffect("Hey my love ??", 100);
    Sleep(800);
    typeEffect("I just wanted to say something...", 100);
    Sleep(1000);
    typeEffect("Every moment with you feels magical ?", 100);
    Sleep(1000);
    typeEffect("You make my world brighter, my heart happier ??", 100);
    Sleep(1000);
    typeEffect("And honestly...", 120);
    Sleep(1200);
    typeEffect("I can’t imagine my life without you ??", 100);
    Sleep(1000);
    typeEffect("So here it goes...", 150);
    Sleep(1200);

    system("color 0A"); // Green color for the big line
    typeEffect("?? Will you be mine forever? ??", 120);
    Sleep(1000);

    cout << endl;
    typeEffect("Type 'yes' if you’ll say YES ??: ", 70);
    string answer;
    cin >> answer;

    if (answer == "yes" || answer == "Yes" || answer == "YES") {
        typeEffect("Yayyy!!! ?? You just made me the happiest person alive! ??", 80);
    } else {
        typeEffect("Aww... even if not today, I’ll keep trying ????", 80);
    }

    Sleep(2000);
    typeEffect("\nI love you forever ??", 100);
    return 0;
}
