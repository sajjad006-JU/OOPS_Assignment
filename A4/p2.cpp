#include <iostream>

using namespace std;
/*
Design a COMPLEX class, which will behave like normal integer with respect to

• addition,
• subtraction,
• accepting the value and
• Displaying the value.

*/

class Complex {
    private:
        float real;
        float imaginary;

    public:
        Complex() {
            real=0;
            imaginary=0;
        }
        Complex(int real, int imaginary) {
            this->real=real;
            this->imaginary=imaginary;
        }

        Complex operator+(const Complex& other) const {
            return Complex(this->real + other.real, this->imaginary+other.imaginary);
        }

        Complex operator-(const Complex& other) const {
            return Complex(this->real - other.real, this->imaginary-other.imaginary);
        }

        // (a+bj) * (c+dj) = ac -bd + (ad+bc)j
        Complex operator*(const Complex& other) const {
            float real=this->real*other.real-this->imaginary*other.imaginary;
            float imaginary=this->real*other.imaginary+this->imaginary*other.real;

            return Complex(real, imaginary);
        }

        Complex operator<<(const Complex& other) const {
            return Complex(this->real - other.real, this->imaginary-other.imaginary);
        }

        friend ostream& operator<<(ostream& os, Complex& c) {
            os << c.real << " + " << c.imaginary << "j\n";
            return os;
        }

        friend istream& operator>>(istream& is, Complex& c) {
            is >> c.real >>  c.imaginary;
            return is;
        }
};

int main() {
    Complex c1;
    Complex c2;

    cin >> c1;
    cin >> c2;

    Complex c3=c1+c2;
    cout << c3;
}