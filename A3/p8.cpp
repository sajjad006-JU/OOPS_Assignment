#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Stack {
    int arr[MAX_SIZE];
    int top;

    public:
        Stack() {
            top=-1;
        }

        void push(int x) {
            if (top>=MAX_SIZE) {
                cout << "Stack overflow";
                return;
            }
            top=top+1;
            arr[top]=x;
        }

        int pop() {
            if (top<0) {
                cout << "Stack underflow";
                return -1;
            }
            int x=arr[top];
            top=top-1;
            return x;
        }

        bool isEmpty() {
            return (top==-1);
        }
};

int main() {
    Stack st;
    st.push(3);
    st.push(4);
    st.push(5);

    while (!st.isEmpty()) {
        cout << st.pop() << "\n";
    }
}