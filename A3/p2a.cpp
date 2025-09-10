#include <iostream>

using namespace std;

int& max(int& a, int& b) {
    if (a>b)
        return a;
    return b;
}

int main () {
    int a, b;
    cout << "enter two numbers: ";
    cin >> a >> b;

    cout << "a = " << a << " & b = " << b << "\n";

    int x=max(a, b);
    cout << "X = " << x << "\n";
    x=21;    
    cout << "X = " << x << "\n";
    cout << "a = " << a << " & b = " << b << "\n";
    return 0;
}