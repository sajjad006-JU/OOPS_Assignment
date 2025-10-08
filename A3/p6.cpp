#include <iostream>

using namespace std;

typedef struct Student {
    int roll;
    float score;

    void takeInput() {
        cout << "Enter roll\n";
        cin >> roll;
        cout << "enter score\n";
        cin >> score;
    }

    void displayData() {
        cout << "Roll: " << roll << " Score: " << score << "\n";
    }
} Student;

void modifyScore(Student& s, int newScore) {
    s.score=newScore;
}

void displayGlobal(Student& s) {
    cout << "Roll: " << s.roll << " Score: " << s.score << "\n";
}

int main () {
    Student s1;
    s1.takeInput();
    s1.displayData();

    modifyScore(s1, 21);
    displayGlobal(s1);
}