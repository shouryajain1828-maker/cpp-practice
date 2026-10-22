#include <iostream>
bool isPrime(int);
void printPrime(int num1,int num2);

int main() {

	int num1, num2;
	std::cout << "Enter two positive integers: ";
	std::cin >> num1 >> num2;
	printPrime(num1,num2);
}
// prints the prime number between num1 and num2
void printPrime(int num1, int num2) {
	if (num1 > num2) {
		// swap if num1 is greater than num2
		std::swap(num1, num2);
	}
	for(int i = num1 + 1 ; i < num2 ; ++i) {
		if (isPrime(i)) {
			std::cout << i << "  ";
		}
	}
}
	// returns true is the given number is true false otherwise
	bool isPrime(int n) {
		bool is_prime = true;
		// 0 and 1 are not prime numbers
		if (n == 0 || n ==  1) {
			return false;
		}
		for(int i = 2; i <= n/2; ++i) {
			if (n % i == 0) {
				return false;
			}
		
           }
		return is_prime;
	}
