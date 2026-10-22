#include <iostream>
using namespace std;

class Student {
	public:
		Student() {
			cout << "Object created" << endl;
		}
		
		~Student() {
			cout << "Object destroyed" << endl;
		}
};

int main() {
	Student s1;
	return 0;
}
