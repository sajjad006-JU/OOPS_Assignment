#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Student {
    int roll;
    string name;
    float score;

    public:
        Student(string name, int roll, float score) {
            this->score=score;
            this->name=name;
            this->roll=roll;
        }

        int getRoll() {
            return roll;
        }

        float getScore() {
            return score;
        }

        string getName() {
            return name;
        }

        void display() const {
            cout << "Roll: " << roll << " | Name: " << name << " | Score: " << score << endl;
        }
};

int main () {
    vector<Student> students;


    int choice;
    while (1) {
        cin >> choice;
        string name, excludeStr, searchStr;
        int roll;
        float score;
        int n=students.size();

        cout << "1.Add student  2.View Student by Roll  3.Number of students  4.With Substr Search  5.Without Substr Search  6.Highest Scorer";

        switch (choice) {
            case 1: {
                cout << "\nEnter name: ";
                cin >> name;

                cout << "\nEnter roll: ";
                cin >> roll;

                cout << "\nEnter score: ";
                cin >> score;

                Student s(name, roll, score);
                students.push_back(s);
                break;
            }
            case 2:
                cout << "\nenter roll to search: ";
                cin >> roll;

                for (int i=0; i<n; i++) {
                    if (students[i].getRoll()==roll) {
                        cout << "Student found!\n";
                        students[i].display();
                        break;
                    }
                }
                cout << "Student not found!";
                break;
            case 3:
                cout << "\nTotal students : " << n;
                break;
            case 4:
                cout << "\nEnter name or sub string to search";
                searchStr;
                cin >> searchStr;

                cout << "--- Students with '" << searchStr << "' in name ---" << endl;
                for (Student s : students) {
                    if (s.getName().find(searchStr) != string::npos) {
                        s.display();
                    }
                }
                cout << endl;
                break;
            case 5:
                cout << "\nEnter name or sub string to exclude: ";
                excludeStr;
                cin >> excludeStr;

                cout << "--- Students without '" << excludeStr << "' in name ---" << endl;
                for (Student s : students) {
                    if (s.getName().find(excludeStr) == string::npos) {
                        s.display();
                    }
                }
                break;
            case 6: {
                Student topper=*max_element(students.begin(), students.end(), [](Student& a, Student& b) {return a.getScore() < b.getScore();});
                topper.display();
                break;
            }
            default:
                break;
        }
    }
}