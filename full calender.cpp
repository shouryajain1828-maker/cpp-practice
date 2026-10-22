#include <iostream>
#include <iomanip>
using namespace std;

// Check leap year
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Days in each month
int getDaysInMonth(int month, int year) {
    if (month == 2) return isLeap(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

// Zeller’s Congruence: returns 0=Sunday, 6=Saturday
int getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13*(month + 1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return ((h + 6) % 7);  
}

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int month = 1; month <= 12; month++) {
        int days = getDaysInMonth(month, year);
        int startDay = getDayOfWeek(1, month, year);

        // Print month header
        cout << "\n\n   " << months[month-1] << " " << year << "\n";
        cout << " Sun Mon Tue Wed Thu Fri Sat\n";

        // Spaces before the first day
        for (int i = 0; i < startDay; i++) cout << "    ";

        // Print days
        for (int d = 1; d <= days; d++) {
            cout << setw(4) << d;
            if ((d + startDay) % 7 == 0) cout << endl;
        }
        cout << endl;
    }

    return 0;
}

