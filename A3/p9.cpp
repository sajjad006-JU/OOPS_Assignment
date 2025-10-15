#include <stdio.h>

class Applicant {
    
    private:
    int score;
    char* name;
    // char name[31];
    int id;
    
    public:
        static int cnt;
        Applicant(char* name, int score) {
            cnt++;
            this->id=cnt+999;
            this->name=name;
            this->score=score;
        }
        
        void showApllicantData() const {
            printf("\nID: %d Name: %s Score: %d\n", id, name, score);
            return;
        }
        
        static int numberOfApplicants() {
            return cnt;
        }
};

int Applicant::cnt=0;

int main () {

    printf("Number of students : %d", Applicant::cnt);

    Applicant a1("sajjad", 21);
    Applicant a2("aritra", 15);
    
    a1.showApllicantData();
    a2.showApllicantData();

    printf("Number of students : %d", Applicant::cnt);
}