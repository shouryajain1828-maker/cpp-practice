#include <iostream>
using namespace std;

class ATM
{
	private:
		int balance;
		
		public:
			ATM()
			{
				balance = 500000;
				
			}
			
			void checkBalance()
			{
				cout << "Your balance is:" << balance << endl;
				
			}
};

int main()
{
	ATM a;
	a.checkBalance();
	
	return 0;
}
