#include <iostream>

using namespace std;

double income_tax(double income, double tax_rate=10) {
    return (income*tax_rate)/100.0;
}

int main () {
    double income, rate;
    cout << "enter income : \n";
    cin >> income;
    cout << "enter tax rate: \n";
    cin >> rate;

    double tax=income_tax(income, rate);
    cout << "calculated tax = " << tax << "\n";

    tax=income_tax(income);
    cout << "calculated tax = " << tax;
    return 0;
}