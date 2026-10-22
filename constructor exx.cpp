#include <iostream>
using namespace std;

class Student {
	public:
		int age;
		
		// Constructor
		Student(int a) {
			age = a;
		}
		
		void display() {
			cout << "Age: " << age;
		}
}; 

int main() {
	Student s1(19);
	s1.display();
	
	return 0;
}
