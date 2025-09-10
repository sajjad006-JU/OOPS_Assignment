#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
    return;
}

int main () {
    int x, y;
    cout << "enter two numbers: ";
    cin >> x >> y;

    swap(x, y);
    cout << "X = " << x << " & Y = " << y;
    return 0;
}