#include <stdlib.h>
#include <iostream>

using namespace std;
/*
Design an ARRAY of integer class with the following features:
a. Array object may be declared for a specific size and a value for initializing
all the elements. Default values for the parameters may be taken as 0.
b. An array object may be declared and initialized with another object.
c. An array object may be declared and initialized with another array (not
the object, standard array as in C language).
Let a and b are two objects:
i. a+b will add corresponding elements.
ii. a=b will do the assignment.
iii. a[I] will return the ith element of the object.
iv. a*5 or 5*a will multiply the elements with 5.
*/

class Array {
    private:
        int size;
        int* arr;

    public:
        Array(int size, int default_value=0) {
            this->size=size;
            // arr=(int *)malloc(size*default_value);
            arr=new int[size];

            for (int i=0; i<size; i++) {
                arr[i]=default_value;
            }
        }

        Array(const Array& other) {
            size=other.size;
            arr=new int[size];
            
            for (int i=0; i<size; i++) {
                arr[i]=other.arr[i];
            }
        }

        Array(int other[]) {
            size=sizeof(other)/sizeof(int);
            arr=new int[size];

            for (int i=0; i<size; i++) {
                arr[i]=other[i];
            }
        }

        Array operator+(const Array& other) const {
            if (size!=other.size) {
                cout << "Error: Array size dont match!\n";
                return *this;
            }
            Array temp(size);

            for (int i=0; i<size; i++) {
                temp.arr[i]=arr[i]+other.arr[i];
            }
            return temp;
        }

        Array operator*(int val) const {
            Array temp(size);

            for (int i=0; i<size; i++) {
                temp.arr[i]=arr[i]*val;
            }
            return temp;
        }

        int& operator[](int index) {
            if (index<0 || index>=size) {
                cout << "index out of range";
                exit(1);
            }
            return arr[index];
        }

        friend ostream& operator<<(ostream& os, Array& a) {
            cout << "[";
            for (int i=0; i<a.size; i++) {
                cout << a.arr[i] << " ";
            }
            cout << "]";
            cout << "\n";
        }

        friend Array operator*(int val, const Array& a) {
            Array temp(a.size);

            for (int i=0; i<a.size; i++) {
                temp.arr[i]=a.arr[i]*val;
            }
            return temp;
        }

        // assignment operator overloading.....
        // Array& operator=(const Array& other) {

        // }
};

int main() {
    Array a1(4, 5);
    Array a2(4, 1);

    Array a3=a1+a2;
    a3=a3*5;
    cout << a3;
}