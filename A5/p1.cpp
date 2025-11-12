#include <string>

/*
There are number of students. For every student roll (unique), name is to be
stored. For each subject, subject code and name is to be stored. A student can
opt for number of subjects. System should be able to maintain student list,
subject list and will be able to answer: i) which student has selected which
subjects and ii) for a subjects who are the students.
Design the classes and implement. For list consider memory data structure.
*/

using namespace std;

class Student {
    private:
        int roll;
        string name;
    
    public:
        int getRoll() {
            return roll;
        }
};

class Subject {
    private:
        int code;
        string name;
};

class StudentSubject {
    int roll;
    int scode;
};

class StudentList {
    Student list[50];

    public:
    int search(int roll) {
        for (int i=0; i<50; i++) {
            if (list[i].getRoll()==roll) {
                return i;
            }
        }
        return -1;
    }
};

class StudentManagement {
    StudentList students;

      
};