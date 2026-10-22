#include <iostream>
using namespace std;

class Student {
public:
    void display(string name) {
        cout << "Student name: " << name;
    }
};

int main() {
    Student s1;
    s1.display("Rahul");
    return 0;
}
