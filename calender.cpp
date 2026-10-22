#include <iostream>
#include <iomanip>
using namespace std;

// Function to check if a year is leap year
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to return number of days in a given month
int getDaysInMonth(int month, int year) {
    if (month == 2) return isLeap(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

// Zeller’s Congruence to find day of week (0 = Saturday, 1 = Sunday,...)
int getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13*(month + 1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return ((h + 6) % 7); // convert to 0=Sunday, 6=Saturday
}

int main() {
    int year, month;
    cout << "Enter year and month (1-12): ";
    cin >> year >> month;

    int days = getDaysInMonth(month, year);
    int startDay = getDayOfWeek(1, month, year);

    // Print header
    cout << "\n   Calendar - " << month << "/" << year << "\n";
    cout << " Sun Mon Tue Wed Thu Fri Sat\n";

    // Print spaces before first day
    for (int i = 0; i < startDay; i++) {
        cout << "    ";
    }

    // Print all days of month
    for (int d = 1; d <= days; d++) {
        cout << setw(4) << d;
        if ((d + startDay) % 7 == 0) cout << endl;
    }
    cout << endl;

    return 0;
}

