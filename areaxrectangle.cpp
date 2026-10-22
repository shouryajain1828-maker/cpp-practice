#include <iostream>
using namespace std;

// Function prototypes
int areaRectangle(int a, int b);
int perimeterRectangle(int a, int b);

// Function definitions
int areaRectangle(int a, int b) {
	return a * b;
}
int perimeterRectangle(int a, int b) {
	return 2 * (a + b);
}
int main() {
	int a = 5;
	int b = 6;
	cout << "Area ="<<areaRectangle(a,b) <<endl;
	cout << "Perimeter ="<<perimeterRectangle(a,b) <<endl;
	
	return 0;
}
