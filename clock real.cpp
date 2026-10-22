#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;

int main() {
    while (true) {
        // get current system time
        auto now = chrono::system_clock::now();
        time_t t = chrono::system_clock::to_time_t(now);
        tm *ltm = localtime(&t);

        // print in HH:MM:SS format
        cout << "\r" << setfill('0')
             << setw(2) << ltm->tm_hour << ":"
             << setw(2) << ltm->tm_min << ":"
             << setw(2) << ltm->tm_sec << flush;

        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}

