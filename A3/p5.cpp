#include <iostream>

using namespace std;

void f(int a, int b) {
    cout << "Inside f(int, int)\n";
    return;
}

void f(char a, int b) {
    cout << "Inside f(char, int)\n";
    return;
}

int main () {
    char ch='a';
    int a=1, b=2;
    float fl=2.3;

    f(a, ch);
    f(ch, ch);
    // f(fl, fl); // error: call of overloaded ‘f(float&, float&)’ is ambiguous
    return 0;
}