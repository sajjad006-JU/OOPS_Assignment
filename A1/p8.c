#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    int score;
    char* name;
};

void displayData(int n, struct Student** students) {
   for (int i=0; i<n; i++) {
        printf("%d %s %d \n", students[i]->roll, students[i]->name, students[i]->score);
    }
    printf("\n\n");
}

void takeUserInput(int n, struct Student** students) {
    printf("enter roll name and score: \n");
    for (int i=0; i<n; i++) {
        struct Student *student=(struct Student *)malloc(sizeof(struct Student));
        *(students+i)=student;
        student->name=(char *)malloc(sizeof(char)*50);
        scanf("%d", &(student->roll));
        scanf("%s", student->name);
        scanf("%d", &(student->score));
    }
    printf("\n\n");
}

int ascending(int a, int b) {
    return (a>b)?0:1;
}

int descending(int a, int b) {
    return (a>b)?1:0;
}

int compareScore(struct Student student) {
    return student.score;
}

int compareRoll(struct Student student) {
    return student.roll;
}


void sort(int n, struct Student** students, int (*compare)(int, int), int (*compareParam)(struct Student)) {
    int min, index=0;

    for (int i=0; i<n; i++) {
        min=i;
        for (int j=i+1; j<n; j++) {
            if (compare(compareParam(*students[j]), compareParam(*students[min]))) {
                min=j;
            }
        }

        struct Student tempStudent=*students[i];
        *students[i]=*students[min];
        *students[min]=tempStudent;
    }
}

struct Student** allocateMemory(int n) {
    return (struct Student **)malloc(n*sizeof(struct Student *));
} 

int main () {
    int n;
    printf("Enter the number of people: \n");
    scanf("%d", &n);
    struct Student **students=allocateMemory(n); 
    takeUserInput(n, students);
    sort(n, students, descending, compareScore);
    displayData(n, students);
    sort(n, students, ascending, compareRoll);
    displayData(n, students);
    free(students);
    return 0;
}