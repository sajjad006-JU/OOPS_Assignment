#include <iostream>

using namespace std;

void f(int a) {
    cout << "Inside f(int)\n";
    return;
}

void f(float a) {
    cout << "Inside f(float)\n";
    return;
}

int main () {
    float a=21.21;
    double d=22.2345;
    f(21);
    f('a');
    f(a);
    // f(d);

    cout << "\n";
    f(21);
    f('a');
    f(a);
    // f(d);

}