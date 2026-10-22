#include<iostream>
using namespace std;

class student {
	public:
		string name;
		int age;
		student(string n, int a) { //parameterised constructor
		
		name = n;
		age = a;
		}
		void display() {
			cout <<name<<endl;
			cout<<age<<endl;
		}
};

int main() {
	student s("Rahul" ,20);
	s.display();
	return 0;
}
