#include <stdio.h>

class Student {
    
    private:
        int roll;
        char* name;
        char* course;
        char* adm_date;
        int marks[5];
        static int cnt;
    
    public:
        static int getNumberOfStudents() {
            return cnt;
        }

        void admission(int roll, char* name, char* course, char* adm_date) {
            cnt++;
            this->roll=roll;
            this->name=name;
            this->course=course;
            this->adm_date=adm_date;
        }
        
        void receiveMarks(int arr[5]) {
            for (int i=0; i<5; i++)
                marks[i]=arr[i];
        }

        void displayMarksheet() {
            printf("Roll: %d, Name: %s, Course: %s, Adm_date: %s", roll, name, course, adm_date);
            printf("\nMarks: ");
            for (int i=0; i<5;i++) {
                printf("Subject %d: %d\n", i+1, marks[i]);
            }
            printf("\n");
        }
};

int Student::cnt=0;

int main () {

    printf("Number of students : %d", Student::getNumberOfStudents());

    Student s1;
    Student s2;
    
    s1.admission(1, "sajjad", "bcse", "24/10/25");
    s2.admission(2, "arita", "bdfdf", "21/10/25");

    int arr[]={10, 21, 23, 24, 20};
    s1.receiveMarks(arr);
    s1.displayMarksheet();

    printf("Number of students : %d", Student::getNumberOfStudents());
}