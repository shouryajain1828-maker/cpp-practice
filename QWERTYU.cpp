#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // Overloading + operator
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(2, 3), c2(4, 5);
    Complex c3;

    c3 = c1 + c2;   // Calls overloaded + operator

    cout << "Sum of Complex Numbers: ";
    c3.display();

    return 0;
}
