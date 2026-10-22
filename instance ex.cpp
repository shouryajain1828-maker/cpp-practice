#include <iostream>
using namespace std;

class Student {
	public:
		string name;
		int age;
};

int main() {
	Student s1;
	Student s2;
	
	s1.name = "Rahul";
	s1.age = 35;
	
	s2.name = "Mohit";
	s2.age = 32;
	
	cout << s1.name << " " << s1.age << endl;
	cout << s2.name << " " << s2.age << endl;
	return 0;
}
